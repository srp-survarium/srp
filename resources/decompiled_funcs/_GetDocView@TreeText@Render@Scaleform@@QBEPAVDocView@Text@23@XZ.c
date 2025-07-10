Scaleform::Render::Text::DocView *__thiscall Scaleform::Render::TreeText::GetDocView(Scaleform::Render::TreeText *this)
{
  return *(Scaleform::Render::Text::DocView **)(*(_DWORD *)(*(_DWORD *)(((unsigned int)this & 0xFFFFF000) + 0x10)
                                                          + 4
                                                          * ((int)((int)&this[-1] - ((unsigned int)this & 0xFFFFF000))
                                                           / 28)
                                                          + 20)
                                              + 144);
}
