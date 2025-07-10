char __thiscall SpeedTree::CForest::ChangeInstance(
        SpeedTree::CForest *this,
        const struct SpeedTree::CCore *a2,
        const struct SpeedTree::CInstance *a3,
        const struct SpeedTree::CInstance *a4)
{
  bool v5; // [esp+0h] [ebp-Ch]
  char v7; // [esp+Bh] [ebp-1h]

  v7 = 0;
  v5 = a4->m_vPos.x != a3->m_vPos.x || a4->m_vPos.y != a3->m_vPos.y || a4->m_vPos.z != a3->m_vPos.z;
  if ( SpeedTree::CForest::DeleteInstances(this, a2, a3, 1, v5) )
    return SpeedTree::CForest::AddInstances(this, a2, a4, 1);
  return v7;
}
