void __thiscall Scaleform::GFx::DisplayObjContainer::CalcDisplayListHitTestMaskArray(
        Scaleform::GFx::DisplayObjContainer *this,
        Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *phitTest,
        const Scaleform::Render::Point<float> *pt,
        bool testShape)
{
  unsigned int Size; // ebx
  unsigned int v5; // esi
  Scaleform::GFx::DisplayObjectBase *pCharacter; // edi
  int *v7; // ecx
  float *v8; // eax
  char *v9; // edi
  unsigned int v10; // eax
  int v11; // edi
  Scaleform::GFx::DisplayObjectBase *v12; // ecx
  unsigned __int16 *v13; // [esp+10h] [ebp-30h]
  Scaleform::GFx::DisplayObjContainer *i; // [esp+14h] [ebp-2Ch]
  Scaleform::Render::Point<float> result; // [esp+18h] [ebp-28h] BYREF
  Scaleform::Render::Matrix2x4<float> v16; // [esp+20h] [ebp-20h] BYREF

  Size = this->mDisplayList.DisplayObjectArray.Data.Size;
  v5 = 0;
  for ( i = this; v5 < Size; ++v5 )
  {
    pCharacter = this->mDisplayList.DisplayObjectArray.Data.Data[v5].pCharacter;
    v13 = (unsigned __int16 *)pCharacter;
    if ( pCharacter->ClipDepth )
    {
      v7 = (int *)phitTest;
      if ( !phitTest->Size )
      {
        if ( Size >= phitTest->Policy.Capacity )
        {
          Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            phitTest,
            phitTest,
            Size + (Size >> 2));
          v7 = (int *)phitTest;
        }
        v7[1] = Size;
        memset(*v7, 1, Size);
      }
      v8 = (float *)pCharacter->GetMatrix(pCharacter);
      v16.M[0][0] = *v8;
      v16.M[0][1] = v8[1];
      v16.M[0][2] = v8[2];
      v16.M[0][3] = v8[3];
      v16.M[1][0] = v8[4];
      v16.M[1][1] = v8[5];
      v16.M[1][2] = v8[6];
      v16.M[1][3] = v8[7];
      Scaleform::Render::Matrix2x4<float>::TransformByInverse(&v16, &result, pt);
      v9 = &phitTest->Data[v5];
      *v9 = (*(int (__thiscall **)(unsigned __int16 *, Scaleform::Render::Point<float> *, int))(*(_DWORD *)v13 + 244))(
              v13,
              &result,
              1);
      v10 = v5 + 1;
      if ( v5 + 1 < Size )
      {
        v11 = v10;
        do
        {
          v12 = i->mDisplayList.DisplayObjectArray.Data.Data[v11].pCharacter;
          if ( v12 && v12->Depth > v13[30] )
            break;
          phitTest->Data[v10++] = phitTest->Data[v5];
          ++v11;
        }
        while ( v10 < Size );
      }
      this = i;
      v5 = v10 - 1;
    }
  }
}
