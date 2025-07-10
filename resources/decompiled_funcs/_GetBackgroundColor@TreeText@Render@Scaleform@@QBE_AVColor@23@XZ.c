Scaleform::Render::Color *__thiscall Scaleform::Render::TreeText::GetBackgroundColor(
        Scaleform::Render::TreeText *this,
        Scaleform::Render::Color *result)
{
  Scaleform::Render::Color *v2; // eax

  v2 = result;
  if ( *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)this & 0xFFFFF000) + 0x10)
                             + 4 * ((int)((int)&this[-1] - ((unsigned int)this & 0xFFFFF000)) / 28)
                             + 20)
                 + 144) )
    *result = *(Scaleform::Render::Color *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)this & 0xFFFFF000) + 0x10)
                                                                  + 4
                                                                  * ((int)((int)&this[-1]
                                                                         - ((unsigned int)this & 0xFFFFF000))
                                                                   / 28)
                                                                  + 20)
                                                      + 144)
                                          + 248);
  else
    result->Raw = 0;
  return v2;
}
