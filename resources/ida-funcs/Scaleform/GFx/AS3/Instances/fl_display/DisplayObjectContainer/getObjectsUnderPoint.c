void __userpurge Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer::getObjectsUnderPoint(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer *this@<ecx>,
        int a2@<edi>,
        Scaleform::Render::Point<float> *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Point *point)
{
  Scaleform::GFx::DisplayObject *pObject; // esi
  Scaleform::MemoryHeap *MHeap; // eax
  int v7; // eax
  int v8; // ecx
  Scaleform::GFx::AS3::Instances::fl::Array *pV; // ebx
  unsigned int v10; // edi
  int v11; // eax
  _DWORD *v12; // esi
  int v13; // eax
  Scaleform::GFx::AS3::Object *v14; // eax
  Scaleform::GFx::AS3::Value *v15; // eax
  float x; // ecx
  unsigned int v17; // eax
  unsigned int RefCount; // eax
  float v19; // edi
  Scaleform::RefCountNTSImpl **i; // esi
  int m_24; // [esp+198h] [ebp-60h]
  Scaleform::Render::Point<float> v22; // [esp+1A8h] [ebp-50h] BYREF
  Scaleform::Render::Point<float> v23; // [esp+1B0h] [ebp-48h] BYREF
  int v24; // [esp+1B8h] [ebp-40h] BYREF
  _DWORD *v25; // [esp+1BCh] [ebp-3Ch]
  float v26; // [esp+1C0h] [ebp-38h]
  Scaleform::MemoryHeap *v27; // [esp+1C4h] [ebp-34h]
  Scaleform::GFx::AS3::Value v28; // [esp+1CCh] [ebp-2Ch] BYREF
  float v29; // [esp+1DCh] [ebp-1Ch]
  float v30; // [esp+1E0h] [ebp-18h]
  float v31; // [esp+1E4h] [ebp-14h]
  float v32; // [esp+1E8h] [ebp-10h]
  float v33; // [esp+1ECh] [ebp-Ch]
  float v34; // [esp+1F0h] [ebp-8h]
  float v35; // [esp+1F4h] [ebp-4h]

  *(float *)&v28.value.VS._2.VObj = 1.0;
  m_24 = a2;
  v29 = 0.0;
  pObject = this->pDispObj.pObject;
  v30 = 0.0;
  v31 = 0.0;
  v32 = 0.0;
  v34 = 0.0;
  v35 = 0.0;
  v33 = 1.0;
  Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(pObject, (Scaleform::Render::Matrix2x4<float> *)&v28.value.VS._2);
  v22.x = point->x * 20.0;
  v22.y = 20.0 * point->y;
  Scaleform::Render::Matrix2x4<float>::TransformByInverse(
    (Scaleform::Render::Matrix2x4<float> *)&v28.value.VS._2,
    &v23,
    &v22);
  MHeap = this->pTraits.pObject->pVM->MHeap;
  v24 = 0;
  v25 = 0;
  v26 = 0.0;
  v27 = MHeap;
  if ( pObject
    && (v7 = (*(int (__thiscall **)(int, int))(*((_DWORD *)&pObject->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                               + pObject->AvmObjOffset)
                                             + 20))(
               (int)pObject + 4 * pObject->AvmObjOffset,
               m_24)) != 0 )
  {
    v8 = v7 - 36;
  }
  else
  {
    v8 = 0;
  }
  (*(void (__thiscall **)(int, int *, Scaleform::Render::Point<float> *, int))(*(_DWORD *)v8 + 80))(
    v8,
    &v24,
    &v23,
    m_24);
  pV = Scaleform::GFx::AS3::VM::MakeArray(
         this->pTraits.pObject->pVM,
         (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> *)&v22.y)->pV;
  v10 = 0;
  v22.x = v26;
  if ( v26 != 0.0 )
  {
    do
    {
      v11 = v25[v10];
      if ( (*(_BYTE *)(v11 + 63) & 1) != 0 )
      {
        if ( v11 )
          v12 = (_DWORD *)(v11 + 4 * *(unsigned __int8 *)(v11 + 65));
        else
          v12 = 0;
        v13 = v12[2];
        if ( !v13 )
          v13 = v12[1];
        if ( (v13 & 1) != 0 )
          --v13;
        if ( !v13 )
          (*(void (__thiscall **)(_DWORD *, int))(*v12 + 60))(v12, 1);
        v14 = (Scaleform::GFx::AS3::Object *)v12[2];
        if ( !v14 )
          v14 = (Scaleform::GFx::AS3::Object *)v12[1];
        if ( ((unsigned __int8)v14 & 1) != 0 )
          v14 = (Scaleform::GFx::AS3::Object *)((char *)v14 - 1);
        Scaleform::GFx::AS3::Value::Value(&v28, v14);
        Scaleform::GFx::AS3::Impl::SparseArray::PushBack(&pV->SA, v15);
        if ( (v28.Flags & 0x1F) > 9 )
        {
          if ( (v28.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v28);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v28);
        }
      }
      ++v10;
    }
    while ( v10 < LODWORD(v22.x) );
  }
  if ( &v22 != result )
  {
    if ( pV )
      pV->RefCount = (pV->RefCount + 1) & 0x8FBFFFFF;
    x = result->x;
    if ( LODWORD(result->x) )
    {
      if ( (LOBYTE(x) & 1) != 0 )
      {
        LODWORD(result->x) = LODWORD(x) - 1;
      }
      else
      {
        v17 = *(_DWORD *)(LODWORD(x) + 16);
        if ( ((unsigned int)&byte_3FFFFF & v17) != 0 )
        {
          *(_DWORD *)(LODWORD(x) + 16) = v17 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)LODWORD(x));
        }
      }
    }
    LODWORD(result->x) = pV;
  }
  if ( pV )
  {
    if ( ((unsigned __int8)pV & 1) == 0 )
    {
      RefCount = pV->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
      {
        pV->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pV);
      }
    }
  }
  v19 = v26;
  for ( i = (Scaleform::RefCountNTSImpl **)&v25[LODWORD(v26) - 1]; v19 != 0.0; --LODWORD(v19) )
  {
    if ( *i )
      Scaleform::RefCountNTSImpl::Release(*i);
    --i;
  }
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v25);
}
