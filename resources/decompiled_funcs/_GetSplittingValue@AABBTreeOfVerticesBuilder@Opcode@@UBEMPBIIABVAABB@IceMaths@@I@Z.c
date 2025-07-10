double __thiscall Opcode::AABBTreeOfVerticesBuilder::GetSplittingValue(
        Opcode::AABBTreeOfVerticesBuilder *this,
        const unsigned int *primitives,
        signed int nb_prims,
        const IceMaths::AABB *global_box,
        unsigned int axis)
{
  float v5; // xmm0_4
  unsigned int v6; // ebp
  unsigned int v7; // eax
  float v8; // xmm1_4
  const IceMaths::Point *mVertexArray; // esi
  unsigned int v10; // edx
  float v11; // xmm2_4
  float v13; // [esp+0h] [ebp-Ch]
  float SplitValue; // [esp+4h] [ebp-8h]
  float global_boxa; // [esp+18h] [ebp+Ch]

  if ( (this->mSettings.mRules & 0x20) == 0 )
    return *(&global_box->mCenter.x + axis);
  v5 = 0.0;
  v6 = nb_prims;
  v7 = 0;
  v8 = 0.0;
  v13 = 0.0;
  global_boxa = 0.0;
  SplitValue = 0.0;
  if ( nb_prims >= 2 )
  {
    mVertexArray = this->mVertexArray;
    do
    {
      v10 = primitives[v7 + 1];
      v5 = *(&mVertexArray->x + 2 * primitives[v7] + primitives[v7] + axis) + v5;
      v7 += 2;
      v11 = *(&mVertexArray->x + 2 * v10 + v10 + axis) + v8;
      v8 = v11;
    }
    while ( v7 < nb_prims - 1 );
    v6 = nb_prims;
    global_boxa = v11;
    v13 = v5;
  }
  if ( v7 < v6 )
    SplitValue = *(&this->mVertexArray->x + 2 * primitives[v7] + primitives[v7] + axis);
  return (global_boxa + v13 + SplitValue) / (double)v6;
}
