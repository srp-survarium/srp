Scaleform::String *__thiscall Scaleform::Render::TreeText::GetHtmlText(
        Scaleform::Render::TreeText *this,
        Scaleform::String *result)
{
  Scaleform::Render::Text::DocView *v2; // ecx

  v2 = *(Scaleform::Render::Text::DocView **)(*(_DWORD *)(*(_DWORD *)(((unsigned int)this & 0xFFFFF000) + 0x10)
                                                        + 4
                                                        * ((int)((int)&this[-1] - ((unsigned int)this & 0xFFFFF000))
                                                         / 28)
                                                        + 20)
                                            + 144);
  if ( v2 )
    Scaleform::Render::Text::DocView::GetHtml(v2, result);
  else
    Scaleform::String::String(result, (char *)&buf);
  return result;
}
