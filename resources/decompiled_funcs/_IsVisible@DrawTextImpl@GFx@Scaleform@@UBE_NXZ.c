int __thiscall Scaleform::GFx::DrawTextImpl::IsVisible(Scaleform::GFx::DrawTextImpl *this)
{
  return *(_WORD *)(*(_DWORD *)(*(_DWORD *)(((int)this->pTextNode.pObject & 0xFFFFF000) + 0x10)
                              + 4
                              * ((int)((int)&this->pTextNode.pObject[-1] - ((int)this->pTextNode.pObject & 0xFFFFF000))
                               / 28)
                              + 20)
                  + 6)
       & 1;
}
