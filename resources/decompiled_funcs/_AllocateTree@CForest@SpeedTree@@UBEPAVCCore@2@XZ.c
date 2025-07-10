struct SpeedTree::CCore *__thiscall SpeedTree::CForest::AllocateTree(SpeedTree::CForest *this)
{
  SpeedTree::CCore *v3; // [esp+1Ch] [ebp-14h]

  v3 = (SpeedTree::CCore *)SpeedTree::st_allocate<SpeedTree::CCore>("CTree");
  if ( v3 )
    return SpeedTree::CCore::CCore(v3);
  else
    return 0;
}
