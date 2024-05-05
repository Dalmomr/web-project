import pythia8
from ROOT import TFile, TTree, vector

# Configuração do Pythia
pythia = pythia8.Pythia()
pythia.readString("Beams:eCM = 13000")
pythia.readString("SoftQCD:all = on")  # Configuração do processo físico

# Abre o arquivo ROOT
f = TFile("output.root", "RECREATE")

# Cria um TTree para armazenar os eventos
tree = TTree("tree_pythia", "Pythia Events")

# Define as variáveis para armazenar as informações dos eventos
event_id = vector("int")()
particle_id = vector("int")()
particle_px = vector("float")()
particle_py = vector("float")()
particle_pz = vector("float")()

# Cria os branches do TTree para armazenar as informações
tree.Branch("event_id", event_id)
tree.Branch("particle_id", particle_id)
tree.Branch("particle_px", particle_px)
tree.Branch("particle_py", particle_py)
tree.Branch("particle_pz", particle_pz)

# Inicializa o Pythia e gera eventos
pythia.init()
for iEvent in range(1000):
    if not pythia.next():
        continue

    # Preenche as informações do evento
    event_id.push_back(iEvent)
    for particle in pythia.event:
        particle_id.push_back(particle.id())
        particle_px.push_back(particle.px())
        particle_py.push_back(particle.py())
        particle_pz.push_back(particle.pz())

    # Preenche o TTree com as informações do evento atual
    tree.Fill()

    # Limpa as variáveis do evento atual para o próximo evento
    event_id.clear()
    particle_id.clear()
    particle_px.clear()
    particle_py.clear()
    particle_pz.clear()

# Finaliza o Pythia após gerar os eventos
pythia.stat()

# Salva o TTree no arquivo ROOT
f.Write()
f.Close()
