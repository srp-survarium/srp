bool __thiscall Scaleform::Render::TreeText::IsWordWrap(Scaleform::Render::TreeText *this)
{
  int v1; // eax

  if ( *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)this & 0xFFFFF000) + 0x10)
                             + 4 * ((int)((int)&this[-1] - ((unsigned int)this & 0xFFFFF000)) / 28)
                             + 20)
                 + 144) )
    return (*(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)this & 0xFFFFF000) + 0x10)
                                                       + 4
                                                       * ((int)((int)&this[-1] - ((unsigned int)this & 0xFFFFF000))
                                                        / 28)
                                                       + 20)
                                           + 144)
                               + 261) >> 3)
         & 1;
  else
    LOBYTE(v1) = 0;
  return v1;
}
