bool __usercall Opcode::MeshInterface::IsValid@<al>(Opcode::MeshInterface *this@<ecx>, _DWORD *a2@<eax>)
{
  return *a2 && a2[1] && a2[3] && a2[4];
}
