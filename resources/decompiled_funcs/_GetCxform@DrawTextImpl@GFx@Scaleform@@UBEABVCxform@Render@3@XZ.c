const Scaleform::Render::Cxform *__thiscall Scaleform::GFx::DrawTextImpl::GetCxform(Scaleform::GFx::DrawTextImpl *this)
{
  return (const Scaleform::Render::Cxform *)(*(_DWORD *)(*(_DWORD *)(((int)this->pTextNode.pObject & 0xFFFFF000) + 0x10)
                                                       + 4
                                                       * ((int)((int)&this->pTextNode.pObject[-1]
                                                              - ((int)this->pTextNode.pObject & 0xFFFFF000))
                                                        / 28)
                                                       + 20)
                                           + 80);
}
