int __thiscall Scaleform::GFx::MovieImpl::GetEdgeAAMode(Scaleform::GFx::MovieImpl *this)
{
  return *(_WORD *)(*(_DWORD *)(*(_DWORD *)(((int)this->pRenderRoot.pObject & 0xFFFFF000) + 0x10)
                              + 4
                              * ((int)((int)&this->pRenderRoot.pObject[-1]
                                     - ((int)this->pRenderRoot.pObject & 0xFFFFF000))
                               / 28)
                              + 20)
                  + 6)
       & 0xC;
}
