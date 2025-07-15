void __userpurge GIM_TRIANGLE_CONTACT::merge_points(
        GIM_TRIANGLE_CONTACT *this@<ecx>,
        int a2@<eax>,
        const btVector4 *plane,
        float margin,
        const btVector3 *points,
        int point_count)
{
  int v6; // edx
  float *v8; // esi
  float v9; // xmm0_4
  int v10; // ecx
  int v11; // ecx
  _DWORD *v12; // edx
  _DWORD *v13; // esi
  _DWORD v14[16]; // [esp+0h] [ebp-40h]

  v6 = 0;
  *(_QWORD *)a2 = LODWORD(FLOAT_N1000_0);
  if ( (int)points > 0 )
  {
    v8 = (float *)(LODWORD(margin) + 4);
    do
    {
      v9 = *(float *)&plane
         - (float)((float)((float)((float)(v8[1] * *((float *)&this->m_point_count + 1))
                                 + (float)(*(v8 - 1) * this->m_penetration_depth))
                         + (float)(*v8 * *(float *)&this->m_point_count))
                 - *((float *)&this->m_point_count + 2));
      if ( v9 >= 0.0 )
      {
        if ( v9 <= *(float *)a2 )
        {
          if ( (float)(v9 + 0.00000011920929) >= *(float *)a2 )
          {
            v10 = *(_DWORD *)(a2 + 4);
            v14[v10] = v6;
            *(_DWORD *)(a2 + 4) = v10 + 1;
          }
        }
        else
        {
          *(float *)a2 = v9;
          v14[0] = v6;
          *(_DWORD *)(a2 + 4) = 1;
        }
      }
      ++v6;
      v8 += 4;
    }
    while ( v6 < (int)points );
  }
  v11 = 0;
  if ( *(int *)(a2 + 4) > 0 )
  {
    v12 = (_DWORD *)(a2 + 32);
    do
    {
      v13 = (_DWORD *)(LODWORD(margin) + 16 * v14[v11]);
      *v12 = *v13++;
      v12[1] = *v13++;
      v12[2] = *v13;
      ++v11;
      v12[3] = v13[1];
      v12 += 4;
    }
    while ( v11 < *(_DWORD *)(a2 + 4) );
  }
}
