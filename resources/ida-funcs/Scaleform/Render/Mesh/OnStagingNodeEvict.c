void __thiscall Scaleform::Render::Mesh::OnStagingNodeEvict(Scaleform::Render::Mesh *this)
{
  bool v1; // zf
  char *v2; // eax
  unsigned int IndexCount; // ecx

  v1 = this->MGFlags == 0;
  this->pPrev = 0;
  if ( v1 )
  {
    v2 = (char *)(&this[-1].LargeMesh + 8);
    IndexCount = this->IndexCount;
    if ( IndexCount )
      (*(void (__thiscall **)(unsigned int, char *))(*(_DWORD *)IndexCount + 16))(IndexCount, v2);
  }
}
