int __thiscall Scaleform::Render::TreeText::GetAAMode(Scaleform::Render::TreeText *this)
{
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
                               + 261) >> 6)
         & 1;
  else
    return 0;
}
