char *__thiscall SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CGrassCell,1>::CNode::CNode(
        char *this,
        _DWORD *a2,
        int a3)
{
  int v3; // edx
  SpeedTree::CCell *v6; // [esp+4h] [ebp-10h]

  v3 = a2[1];
  *(_DWORD *)this = *a2;
  *((_DWORD *)this + 1) = v3;
  v6 = (SpeedTree::CCell *)(this + 8);
  SpeedTree::CCell::CCell((SpeedTree::CCell *)(this + 8));
  v6->__vftable = (SpeedTree::CCell_vtbl *)&SpeedTree::CGrassCell::`vftable';
  v6[1].__vftable = 0;
  v6[1].m_nRow = 0;
  *(float *)&v6[1].m_nCol = 0.0;
  *((_DWORD *)this + 19) = 0;
  *((_DWORD *)this + 20) = 0;
  *((_DWORD *)this + 21) = a3;
  *((_DWORD *)this + 22) = 0;
  return this;
}
