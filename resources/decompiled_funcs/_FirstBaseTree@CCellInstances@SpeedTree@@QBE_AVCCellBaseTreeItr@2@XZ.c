struct SpeedTree::CCellBaseTreeItr *__thiscall SpeedTree::CCellInstances::FirstBaseTree(
        SpeedTree::CCellInstances *this,
        struct SpeedTree::CCellBaseTreeItr *__return_ptr retstr)
{
  int v4; // [esp+14h] [ebp-50h]
  const SpeedTree::CBlockPool<1> *v5; // [esp+18h] [ebp-4Ch]
  _BYTE v6[8]; // [esp+2Ch] [ebp-38h] BYREF
  int v7; // [esp+34h] [ebp-30h]
  void *v8; // [esp+38h] [ebp-2Ch]
  SpeedTree::CCellBaseTreeItr v9; // [esp+4Ch] [ebp-18h] BYREF
  int v10; // [esp+60h] [ebp-4h]

  v7 = 0;
  memset(&v9, 0, sizeof(v9));
  v10 = 0;
  v4 = SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::begin(v6);
  v5 = *(const SpeedTree::CBlockPool<1> **)(v4 + 4);
  v8 = *(void **)v4;
  v9.m_pCell = this;
  retstr->m_iBaseTreeItr.m_pNode = v8;
  retstr->m_iBaseTreeItr.m_pPool = v5;
  retstr->m_pCell = v9.m_pCell;
  return retstr;
}
