void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Scene::labelsGet(
        Scaleform::GFx::AS3::Instances::fl_display::Scene *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::Scene *v2; // ebp
  Scaleform::GFx::AS3::ASVM *pVM; // ebx
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> *Array; // eax
  Scaleform::GFx::AS3::Instances::fl::Array *pV; // esi
  Scaleform::GFx::AS3::Instances::fl::Array *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Traits *v8; // edx
  const Scaleform::GFx::MovieDataDef::SceneInfo *SceneInfo; // eax
  unsigned int v10; // esi
  unsigned int Size; // eax
  int v12; // ebp
  const Scaleform::GFx::MovieDataDef::SceneInfo *v13; // ecx
  Scaleform::GFx::MovieDataDef::FrameLabelInfo *Data; // eax
  Scaleform::GFx::AS3::Instances::fl_display::FrameLabel *v15; // esi
  Scaleform::GFx::ASStringNode *StringNode; // edi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v18; // zf
  unsigned int v19; // edx
  Scaleform::GFx::AS3::Instances::fl_display::FrameLabel *v20; // ecx
  unsigned int v21; // edi
  unsigned int v22; // ebp
  Scaleform::GFx::ASStringNode *v23; // esi
  unsigned int v24; // eax
  Scaleform::GFx::AS3::Instances::fl_display::FrameLabel *v25; // edi
  Scaleform::GFx::ASStringNode *v26; // ecx
  unsigned int v27; // edx
  Scaleform::GFx::AS3::Instances::fl_display::FrameLabel *v28; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::FrameLabel> frameLabel; // [esp+10h] [ebp-40h] BYREF
  unsigned int i; // [esp+14h] [ebp-3Ch]
  Scaleform::GFx::AS3::Class *frameLabelClassVal; // [esp+18h] [ebp-38h]
  Scaleform::GFx::AS3::Instances::fl_display::Scene *v32; // [esp+1Ch] [ebp-34h]
  unsigned int nj; // [esp+20h] [ebp-30h]
  unsigned int cnt; // [esp+24h] [ebp-2Ch] BYREF
  Scaleform::StringDataPtr gname; // [esp+28h] [ebp-28h] BYREF
  Scaleform::Array<Scaleform::String,2,Scaleform::ArrayDefaultPolicy> labels; // [esp+30h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value v; // [esp+40h] [ebp-10h] BYREF

  v2 = this;
  pVM = (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM;
  v32 = this;
  Array = Scaleform::GFx::AS3::VM::MakeArray(
            pVM,
            (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> *)&cnt);
  pV = Array->pV;
  pObject = result->pObject;
  if ( Array->pV != result->pObject )
  {
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl::Array *)((char *)pObject - 1);
      }
      else
      {
        RefCount = pObject->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
      }
    }
    result->pObject = pV;
  }
  v8 = v2->pTraits.pObject;
  gname.pStr = "flash.display.FrameLabel";
  gname.Size = 24;
  frameLabelClassVal = Scaleform::GFx::AS3::VM::GetClass(v8->pVM, &gname, v8->pVM->CurrentDomain);
  SceneInfo = v2->SceneInfo;
  v10 = 0;
  if ( SceneInfo )
  {
    Size = SceneInfo->Labels.Data.Size;
    if ( Size )
    {
      v12 = 0;
      i = Size;
      do
      {
        frameLabel.pObject = 0;
        Scaleform::GFx::AS3::ASVM::_constructInstance(
          pVM,
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&frameLabel,
          frameLabelClassVal,
          0,
          0);
        v13 = v32->SceneInfo;
        Data = v13->Labels.Data.Data;
        v15 = frameLabel.pObject;
        frameLabel.pObject->FrameNumber = Data[v12].Number - v13->Offset + 1;
        StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                       v15->FrameName.pNode->pManager,
                       (__m128i *)((Data[v12].Name.HeapTypeBits & 0xFFFFFFFC) + 8),
                       *(_DWORD *)(Data[v12].Name.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
        ++StringNode->RefCount;
        pNode = v15->FrameName.pNode;
        v18 = pNode->RefCount-- == 1;
        if ( v18 )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        v15->FrameName.pNode = StringNode;
        labels.Data.Data = 0;
        labels.Data.Size = 0;
        Scaleform::GFx::AS3::Value::AssignUnsafe((Scaleform::GFx::AS3::Value *)&labels, frameLabel.pObject);
        Scaleform::GFx::AS3::Impl::SparseArray::PushBack(&result->pObject->SA, (Scaleform::GFx::AS3::Value *)&labels);
        if ( ((int)labels.Data.Data & 0x1F) > 9u )
        {
          if ( ((int)labels.Data.Data & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef((Scaleform::GFx::AS3::Value *)&labels);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&labels);
        }
        if ( frameLabel.pObject && ((int)frameLabel.pObject & 1) == 0 )
        {
          v19 = frameLabel.pObject->RefCount;
          if ( (v19 & 0x3FFFFF) != 0 )
          {
            v20 = frameLabel.pObject;
            frameLabel.pObject->RefCount = v19 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v20);
          }
        }
        ++v12;
        --i;
      }
      while ( i );
    }
  }
  else
  {
    v21 = v2->SpriteObj.pObject->pDef.pObject->GetFrameCount(v2->SpriteObj.pObject->pDef.pObject);
    cnt = v21;
    memset(&labels, 0, sizeof(labels));
    i = 0;
    if ( v21 )
    {
      do
      {
        if ( v2->SpriteObj.pObject->pDef.pObject->GetFrameLabels(v2->SpriteObj.pObject->pDef.pObject, v10, &labels) )
        {
          v22 = 0;
          nj = labels.Data.Size;
          if ( !labels.Data.Size )
            goto LABEL_44;
          do
          {
            frameLabel.pObject = 0;
            Scaleform::GFx::AS3::ASVM::_constructInstance(
              pVM,
              (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&frameLabel,
              frameLabelClassVal,
              0,
              0);
            v23 = Scaleform::GFx::ASStringManager::CreateStringNode(
                    pVM->StringManagerRef->pStringManager,
                    (__m128i *)((labels.Data.Data[v22].HeapTypeBits & 0xFFFFFFFC) + 8));
            v24 = i;
            ++v23->RefCount;
            v25 = frameLabel.pObject;
            frameLabel.pObject->FrameNumber = v24 + 1;
            ++v23->RefCount;
            v26 = v25->FrameName.pNode;
            v18 = v26->RefCount-- == 1;
            if ( v18 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v26);
            v25->FrameName.pNode = v23;
            v18 = v23->RefCount-- == 1;
            if ( v18 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v23);
            v.Flags = 0;
            v.Bonus.pWeakProxy = 0;
            Scaleform::GFx::AS3::Value::AssignUnsafe(&v, frameLabel.pObject);
            Scaleform::GFx::AS3::Impl::SparseArray::PushBack(&result->pObject->SA, &v);
            if ( (v.Flags & 0x1F) > 9 )
            {
              if ( (v.Flags & 0x200) != 0 )
                Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
              else
                Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
            }
            if ( frameLabel.pObject )
            {
              if ( ((int)frameLabel.pObject & 1) == 0 )
              {
                v27 = frameLabel.pObject->RefCount;
                v28 = frameLabel.pObject;
                if ( (v27 & 0x3FFFFF) != 0 )
                {
                  frameLabel.pObject->RefCount = v27 - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v28);
                }
              }
            }
            ++v22;
          }
          while ( v22 < nj );
          if ( labels.Data.Size )
          {
            Scaleform::ConstructorMov<Scaleform::String>::DestructArray(labels.Data.Data, labels.Data.Size);
            if ( (labels.Data.Policy.Capacity & 0xFFFFFFFE) != 0 )
            {
              if ( labels.Data.Data )
              {
                Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, labels.Data.Data);
                labels.Data.Data = 0;
              }
              labels.Data.Policy.Capacity = 0;
            }
          }
          else
          {
LABEL_44:
            if ( !labels.Data.Policy.Capacity )
              Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)&labels,
                &labels,
                0);
          }
          v2 = v32;
          v21 = cnt;
          v10 = i;
          labels.Data.Size = 0;
        }
        i = ++v10;
      }
      while ( v10 < v21 );
    }
    Scaleform::ConstructorMov<Scaleform::String>::DestructArray(labels.Data.Data, labels.Data.Size);
    if ( labels.Data.Data )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, labels.Data.Data);
  }
}
