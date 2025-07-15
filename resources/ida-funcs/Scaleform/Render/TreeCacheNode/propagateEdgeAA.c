void __thiscall Scaleform::Render::TreeCacheNode::propagateEdgeAA(
        Scaleform::Render::TreeCacheNode *this,
        Scaleform::Render::EdgeAAMode parentEdgeAA)
{
  int v2; // eax

  if ( parentEdgeAA == EdgeAA_Disable )
  {
    LOWORD(v2) = 12;
  }
  else
  {
    v2 = *(_WORD *)((*(_DWORD *)(*(_DWORD *)(((int)this->pNode & 0xFFFFF000) + 0x14)
                               + 4 * ((int)((int)&this->pNode[-1] - ((int)this->pNode & 0xFFFFF000)) / 28)
                               + 20)
                   & 0xFFFFFFFE)
                  + 6)
       & 0xC;
    if ( !v2 )
      LOWORD(v2) = parentEdgeAA;
  }
  this->Flags = v2 | this->Flags & 0xFFF3;
}
