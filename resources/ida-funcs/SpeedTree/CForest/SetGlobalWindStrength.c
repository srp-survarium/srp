void __usercall SpeedTree::CForest::SetGlobalWindStrength(SpeedTree::CForest *this@<ecx>, int a2@<esi>)
{
  unsigned int v2; // edi
  SpeedTree::CWind *Wind; // eax
  float v4; // [esp+0h] [ebp-8h]

  v2 = 0;
  for ( *(float *)(a2 + 104) = FLOAT_0_1; v2 < *(_DWORD *)(a2 + 12); ++v2 )
  {
    v4 = *(float *)(a2 + 104);
    Wind = SpeedTree::CCore::GetWind(*(SpeedTree::CCore **)(*(_DWORD *)(a2 + 8) + 4 * v2));
    SpeedTree::CWind::SetStrength(Wind, v4);
  }
  SpeedTree::CWind::SetStrength((SpeedTree::CWind *)(a2 + 124), *(float *)(a2 + 104));
}
