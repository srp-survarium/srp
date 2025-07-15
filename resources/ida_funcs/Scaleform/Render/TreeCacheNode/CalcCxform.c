void __thiscall Scaleform::Render::TreeCacheNode::CalcCxform(
        Scaleform::Render::TreeCacheNode *this,
        Scaleform::Render::Cxform *dest)
{
  Scaleform::Render::TreeCacheNode **p_pParent; // esi
  Scaleform::Render::TreeCacheNode *v3; // eax
  bool v4; // zf

  qmemcpy(
    dest,
    (const void *)((*(_DWORD *)(*(_DWORD *)(((int)this->pNode & 0xFFFFF000) + 0x14)
                              + 4 * ((int)((int)&this->pNode[-1] - ((int)this->pNode & 0xFFFFF000)) / 28)
                              + 20)
                  & 0xFFFFFFFE)
                 + 80),
    sizeof(Scaleform::Render::Cxform));
  p_pParent = &this->pParent;
  v3 = this;
  if ( this->pParent )
  {
    do
    {
      Scaleform::Render::Cxform::Prepend(
        dest,
        (const Scaleform::Render::Cxform *)((*(_DWORD *)(*(_DWORD *)(((int)v3->pNode & 0xFFFFF000) + 0x14)
                                                       + 4
                                                       * ((int)((int)&v3->pNode[-1] - ((int)v3->pNode & 0xFFFFF000))
                                                        / 28)
                                                       + 20)
                                           & 0xFFFFFFFE)
                                          + 80));
      v3 = *p_pParent;
      v4 = (*p_pParent)->pParent == 0;
      p_pParent = &(*p_pParent)->pParent;
    }
    while ( !v4 );
  }
}
