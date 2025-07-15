void __thiscall Scaleform::Render::D3D1x::ShaderInterface::Finish(
        Scaleform::Render::D3D1x::ShaderInterface *this,
        unsigned int meshCount)
{
  Scaleform::Render::D3D1x::ShaderConstantRange *v3; // ecx
  _BYTE *v4; // eax
  int i; // edi
  int v6; // eax
  int v7; // ecx
  Scaleform::Render::D3D1x::ShaderConstantRange *v8; // esi
  Scaleform::Render::D3D1x::ShaderConstantRange *v9; // ecx
  int v10; // esi
  int v11; // eax
  int v12; // edi
  int v13; // eax
  char v14; // [esp+0h] [ebp-44h]
  char v15; // [esp+0h] [ebp-44h]
  _DWORD v16[5]; // [esp+Ch] [ebp-38h] BYREF
  int v17; // [esp+20h] [ebp-24h]
  _DWORD v18[6]; // [esp+24h] [ebp-20h] BYREF
  _BYTE *v19; // [esp+3Ch] [ebp-8h]
  int v20; // [esp+4Ch] [ebp+8h]

  v3 = 0;
  v17 = *(_DWORD *)(meshCount + 4384);
  v18[5] = v17;
  v4 = (_BYTE *)(meshCount + 4352);
  v16[0] = meshCount;
  v16[4] = 0;
  v18[0] = meshCount;
  v18[4] = 0;
  v20 = 0;
  v19 = v4;
  for ( i = 8; i < 68; i += 4 )
  {
    if ( !*v19 )
      goto LABEL_8;
    v6 = *(_DWORD *)(*(_DWORD *)(meshCount + 4396) + i + 4);
    if ( v6 < 0 )
    {
      v6 = *(_DWORD *)(i + *(_DWORD *)(meshCount + 4388));
      if ( v6 < 0 )
        goto LABEL_8;
      v7 = *(_DWORD *)(meshCount + 4392);
      v8 = (Scaleform::Render::D3D1x::ShaderConstantRange *)v18;
    }
    else
    {
      v7 = *(_DWORD *)(meshCount + 4400);
      v8 = (Scaleform::Render::D3D1x::ShaderConstantRange *)v16;
    }
    Scaleform::Render::D3D1x::ShaderConstantRange::Update(
      v8,
      v6,
      *(__int16 *)(v20 + *(_DWORD *)(v7 + 20) + 6),
      *(__int16 *)(v20 + *(_DWORD *)(v7 + 20) + 2));
LABEL_8:
    v20 += 10;
    ++v19;
  }
  Scaleform::Render::D3D1x::ShaderConstantRange::Finish(v3, (int)v18, 0, v14);
  Scaleform::Render::D3D1x::ShaderConstantRange::Finish(v9, (int)v16, 1, v15);
  *(_DWORD *)(meshCount + 4352) = 0;
  *(_DWORD *)(meshCount + 4356) = 0;
  *(_DWORD *)(meshCount + 4360) = 0;
  *(_WORD *)(meshCount + 4364) = 0;
  *(_BYTE *)(meshCount + 4366) = 0;
  v10 = *(_DWORD *)(*(_DWORD *)(meshCount + 4384) + 63956);
  v11 = *(_DWORD *)(*(_DWORD *)(meshCount + 4388) + 4);
  if ( *(_DWORD *)(meshCount + 4408) != v11 )
  {
    (*(void (__stdcall **)(int, int, _DWORD, _DWORD))(*(_DWORD *)v10 + 44))(v10, v11, 0, 0);
    *(_DWORD *)(meshCount + 4408) = *(_DWORD *)(*(_DWORD *)(meshCount + 4388) + 4);
  }
  v12 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(meshCount + 4404) + 8) + 8);
  if ( *(_DWORD *)(meshCount + 4416) != v12 )
  {
    (*(void (__stdcall **)(int, int))(*(_DWORD *)v10 + 68))(v10, v12);
    *(_DWORD *)(meshCount + 4416) = v12;
  }
  v13 = *(_DWORD *)(*(_DWORD *)(meshCount + 4396) + 4);
  if ( *(_DWORD *)(meshCount + 4412) != v13 )
  {
    (*(void (__stdcall **)(int, int, _DWORD, _DWORD))(*(_DWORD *)v10 + 36))(v10, v13, 0, 0);
    *(_DWORD *)(meshCount + 4412) = *(_DWORD *)(*(_DWORD *)(meshCount + 4396) + 4);
  }
}
