void __cdecl SpeedTree::ComputeCellCoords(SpeedTree *this, const struct SpeedTree::Vec3 *a2, int *a3, int *a4)
{
  int v4; // [esp+0h] [ebp-14h]
  int v5; // [esp+4h] [ebp-10h]
  struct SpeedTree::Vec3 v6; // [esp+8h] [ebp-Ch] BYREF

  SpeedTree::CCoordSys::ConvertToStd(&v6, (const float *)this);
  if ( v6.y >= 0.0 )
    v5 = (int)(v6.y / *(float *)&a2);
  else
    v5 = (int)((v6.y - *(float *)&a2) / *(float *)&a2);
  *a3 = v5;
  if ( v6.x >= 0.0 )
    v4 = (int)(v6.x / *(float *)&a2);
  else
    v4 = (int)((v6.x - *(float *)&a2) / *(float *)&a2);
  *a4 = v4;
}
