double __usercall vostok::physics::bullet_character_controller::recover_from_penetration@<st0>(
        vostok::physics::bullet_character_controller *this@<ecx>,
        int a2@<eax>,
        double result@<st0>)
{
  CProfileNode *Sub_Node; // eax
  int RecursionCounter; // ecx
  int v6; // eax
  btClock *v7; // ecx
  int v8; // edi
  int v9; // ecx
  int v10; // eax
  int v11; // eax
  int v12; // eax
  const vostok::math::float4x4 *v13; // xmm7_4
  int v14; // edx
  int v15; // ecx
  bool v16; // bl
  float v17; // xmm5_4
  int v18; // edi
  float *v19; // eax
  float v20; // xmm4_4
  float *v21; // ecx
  float v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm2_4
  float v25; // xmm3_4
  float v26; // xmm4_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  _QWORD *v29; // eax
  __int64 v30; // xmm1_8
  __int64 v31; // xmm2_8
  __int64 v32; // xmm3_8
  __int64 v33; // xmm4_8
  __int64 v34; // xmm5_8
  __int64 v35; // xmm6_8
  __int64 v36; // xmm7_8
  CProfileNode *v37; // edi
  int *p_RecursionCounter; // esi
  bool v39; // zf
  int v40; // [esp+160h] [ebp-4Ch]
  float v41; // [esp+164h] [ebp-48h]
  int v42; // [esp+168h] [ebp-44h]
  int v43; // [esp+16Ch] [ebp-40h]
  int v44; // [esp+16Ch] [ebp-40h]
  int v45; // [esp+170h] [ebp-3Ch]
  int v46; // [esp+198h] [ebp-14h] BYREF
  int v47; // [esp+19Ch] [ebp-10h]
  int v48; // [esp+1A0h] [ebp-Ch]
  void *ptr; // [esp+1A4h] [ebp-8h]
  char v50; // [esp+1A8h] [ebp-4h]

  Sub_Node = CProfileManager::CurrentNode;
  if ( CProfileManager::CurrentNode->Name != "recover_from_penetration" )
  {
    Sub_Node = CProfileNode::Get_Sub_Node((const char *)this);
    CProfileManager::CurrentNode = Sub_Node;
  }
  RecursionCounter = Sub_Node->RecursionCounter;
  ++Sub_Node->TotalCalls;
  Sub_Node->RecursionCounter = RecursionCounter + 1;
  if ( !RecursionCounter )
    Sub_Node->StartTime = btClock::getTimeMicroseconds(0);
  (*(void (__stdcall **)(_DWORD, int, _DWORD))(**(_DWORD **)(*(_DWORD *)(a2 + 4) + 24) + 28))(
    *(_DWORD *)(*(_DWORD *)(a2 + 136) + 304),
    *(_DWORD *)(a2 + 4) + 28,
    *(_DWORD *)(*(_DWORD *)(a2 + 4) + 24));
  v6 = *(_DWORD *)(a2 + 136);
  *(_QWORD *)(a2 + 48) = *(_QWORD *)(v6 + 64);
  *(_QWORD *)(a2 + 56) = *(_QWORD *)(v6 + 72);
  v41 = 0.0;
  v43 = *(_DWORD *)(a2 + 100);
  v50 = 1;
  ptr = 0;
  v47 = 0;
  v48 = 0;
  v45 = v43 & 0x7FFFFFFF;
  v44 = 0;
  if ( (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(v6 + 304) + 32))(*(_DWORD *)(v6 + 304)) > 0 )
  {
    v40 = 0;
    do
    {
      v8 = v47;
      if ( v47 < 0 )
      {
        if ( v48 < 0 )
        {
          if ( ptr && v50 )
          {
            ++gNumAlignedFree;
            sAlignedFreeFunc(ptr);
          }
          v50 = 1;
          ptr = 0;
          v48 = 0;
        }
        if ( v8 < 0 )
        {
          v9 = 4 * v8;
          do
          {
            if ( (char *)ptr + v9 )
              *(_DWORD *)((char *)ptr + v9) = 0;
            v9 += 4;
          }
          while ( v9 < 0 );
        }
      }
      v10 = *(_DWORD *)(a2 + 136);
      v47 = 0;
      v11 = v40
          + *(_DWORD *)((*(int (__usercall **)@<eax>(_DWORD@<ecx>, double@<st0>))(**(_DWORD **)(v10 + 304) + 24))(
                          *(_DWORD *)(v10 + 304),
                          result)
                      + 12);
      if ( *(_DWORD *)(v11 + 8) )
        (*(void (__thiscall **)(_DWORD, int *))(**(_DWORD **)(v11 + 8) + 12))(*(_DWORD *)(v11 + 8), &v46);
      v12 = 0;
      v42 = 0;
      if ( v47 > 0 )
      {
        v13 = clear_value;
        do
        {
          v14 = *((_DWORD *)ptr + v12);
          v15 = *(_DWORD *)(v14 + 1168);
          v16 = v15 == *(_DWORD *)(a2 + 136);
          if ( v15 == *(_DWORD *)(a2 + 136) )
            v17 = -1.0;
          else
            v17 = *(float *)&v13;
          v18 = 0;
          if ( *(int *)(v14 + 1176) > 0 )
          {
            v19 = (float *)(v14 + 88);
            do
            {
              v20 = v19[2];
              if ( v20 < 0.0 && v41 > v20 )
              {
                v41 = v19[2];
                v21 = v19 - 18;
                if ( !v16 )
                  v21 = v19 - 14;
                v22 = (float)((float)((float)(*(float *)&v45 - COERCE_FLOAT((_DWORD)v21[1] & 0x7FFFFFFF))
                                    / *(float *)&v45)
                            * (float)((float)(*(float *)&v45 - COERCE_FLOAT((_DWORD)v21[1] & 0x7FFFFFFF))
                                    / *(float *)&v45))
                    * (float)((float)(*(float *)&v45 - COERCE_FLOAT((_DWORD)v21[1] & 0x7FFFFFFF)) / *(float *)&v45);
                v23 = (float)((float)(*(v19 - 2) * v17) * v20) * v22;
                v24 = (float)(*(v19 - 1) * v17) * v20;
                v25 = (float)((float)(*v19 * v17) * v20) * v22;
                v26 = *(float *)&v13 - v22;
                v27 = *(float *)(a2 + 48) + v23;
                *(float *)(a2 + 52) = *(float *)(a2 + 52) + (float)(v26 * v24);
                v28 = *(float *)(a2 + 56) + v25;
                *(float *)(a2 + 48) = v27;
                *(float *)(a2 + 56) = v28;
              }
              ++v18;
              v19 += 72;
            }
            while ( v18 < *(_DWORD *)(v14 + 1176) );
            v12 = v42;
          }
          v42 = ++v12;
        }
        while ( v12 < v47 );
      }
      v40 += 16;
      ++v44;
    }
    while ( v44 < (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)(a2 + 136) + 304) + 32))(*(_DWORD *)(*(_DWORD *)(a2 + 136) + 304)) );
  }
  v29 = *(_QWORD **)(a2 + 136);
  v30 = v29[3];
  v31 = v29[4];
  v32 = v29[5];
  v33 = v29[6];
  v34 = v29[7];
  v35 = *(_QWORD *)(a2 + 48);
  v36 = *(_QWORD *)(a2 + 56);
  v29[2] = v29[2];
  v29[4] = v31;
  v29[6] = v33;
  v29[8] = v35;
  v29[3] = v30;
  v29[5] = v32;
  v29[7] = v34;
  v29[9] = v36;
  if ( ptr && v50 )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(ptr);
  }
  v37 = CProfileManager::CurrentNode;
  p_RecursionCounter = &CProfileManager::CurrentNode->RecursionCounter;
  v50 = 1;
  ptr = 0;
  v47 = 0;
  v48 = 0;
  v39 = CProfileManager::CurrentNode->RecursionCounter-- == 1;
  if ( v39 && v37->TotalCalls )
  {
    v37->TotalTime = (double)(btClock::getTimeMicroseconds(v7) - v37->StartTime) * 0.001 + v37->TotalTime;
    v37 = CProfileManager::CurrentNode;
  }
  if ( !*p_RecursionCounter )
    CProfileManager::CurrentNode = v37->Parent;
  return result;
}
