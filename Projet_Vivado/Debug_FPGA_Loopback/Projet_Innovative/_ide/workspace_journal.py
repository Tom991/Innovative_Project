# 2026-01-25T15:57:28.214370620
import vitis

client = vitis.create_client()
client.set_workspace(path="Projet_Innovative")

platform = client.get_component(name="platform")
status = platform.build()

comp = client.get_component(name="hello_world")
comp.build()

status = platform.build()

comp.build()

