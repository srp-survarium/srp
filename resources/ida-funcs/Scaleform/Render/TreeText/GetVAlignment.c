int __thiscall Scaleform::Render::TreeText::GetVAlignment(Scaleform::Render::TreeText *this)
{
  if ( *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)this & 0xFFFFF000) + 0x10)
                             + 4 * ((int)((int)&this[-1] - ((unsigned int)this & 0xFFFFF000)) / 28)
                             + 20)
                 + 144) )
  {
    if ( ((*(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)this & 0xFFFFF000) + 0x10)
                                                      + 4
                                                      * ((int)((int)&this[-1] - ((unsigned int)this & 0xFFFFF000))
                                                       / 28)
                                                      + 20)
                                          + 144)
                              + 260) >> 2)
        & 3) == 2 )
      return 2;
    if ( ((*(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)this & 0xFFFFF000) + 0x10)
                                                      + 4
                                                      * ((int)((int)&this[-1] - ((unsigned int)this & 0xFFFFF000))
                                                       / 28)
                                                      + 20)
                                          + 144)
                              + 260) >> 2)
        & 3) == 3 )
      return 1;
  }
  return 0;
}
