# 2026-01-25T12:00:30.171455965
import vitis

client = vitis.create_client()
client.set_workspace(path="Projet_Innovative")

platform = client.get_component(name="platform")
status = platform.build()

comp = client.get_component(name="hello_world")
comp.build()

status = platform.build()

comp.build()

vitis.dispose()

