void __cdecl Scaleform::GFx::AS3::InstanceTraits::fl::String::AS3split(
        const Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::ASStringNode *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::VM *v6; // ebx
  Scaleform::GFx::AS3::Instances::fl::Array *RefCount; // ebp
  Scaleform::GFx::ASStringNode *v8; // eax
  Scaleform::GFx::ASStringNode *v9; // ecx
  unsigned int v10; // edi
  char Flags; // al
  const Scaleform::GFx::AS3::Value *v12; // esi
  Scaleform::GFx::AS3::Instances::fl::RegExp *VInt; // ebp
  unsigned int v14; // edi
  Scaleform::GFx::ASStringManager *pStringManager; // eax
  Scaleform::GFx::AS3::Instances::fl::Array *pV; // esi
  Scaleform::GFx::AS3::Instances::fl::Object *pObject; // ecx
  unsigned int v18; // edx
  bool v19; // bl
  unsigned int v20; // eax
  const char *MatchOffset; // edi
  int MatchLength; // ebx
  unsigned int Length; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  unsigned int v25; // ebx
  const char *v26; // eax
  Scaleform::GFx::ASString *v27; // eax
  unsigned int v28; // ecx
  Scaleform::GFx::ASStringNode *v29; // eax
  Scaleform::GFx::ASStringNode *v30; // eax
  Scaleform::GFx::ASStringNode *v31; // eax
  Scaleform::GFx::AS3::Object **v32; // eax
  Scaleform::GFx::ASStringNode *v33; // eax
  Scaleform::GFx::ASStringNode *v34; // eax
  Scaleform::GFx::ASString str; // [esp+Ch] [ebp-50h] BYREF
  int v36; // [esp+10h] [ebp-4Ch]
  unsigned int limit; // [esp+14h] [ebp-48h]
  Scaleform::GFx::ASString delimStr; // [esp+18h] [ebp-44h] BYREF
  unsigned int next; // [esp+1Ch] [ebp-40h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> v40; // [esp+20h] [ebp-3Ch] BYREF
  Scaleform::GFx::ASString v; // [esp+24h] [ebp-38h] BYREF
  unsigned int cnt; // [esp+28h] [ebp-34h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::RegExp> pre; // [esp+2Ch] [ebp-30h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> parr; // [esp+30h] [ebp-2Ch] BYREF
  Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeRef nlimit; // [esp+34h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::Value delimiter; // [esp+3Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value val; // [esp+4Ch] [ebp-10h] BYREF

  v6 = (Scaleform::GFx::AS3::VM *)vm;
  RefCount = (Scaleform::GFx::AS3::Instances::fl::Array *)vm->RefCount;
  str.pNode = (Scaleform::GFx::ASStringNode *)(RefCount[2].SA.ValueA.Data.Policy.Capacity + 32);
  ++str.pNode->RefCount;
  v36 = 0;
  parr.pObject = RefCount;
  if ( Scaleform::GFx::AS3::Value::Convert2String(_this, (Scaleform::GFx::AS3::CheckResult *)&vm, &str)->Result )
  {
    v10 = argc;
    Flags = 0;
    delimiter.Bonus.pWeakProxy = 0;
    v12 = argv;
    delimiter.Flags = 0;
    if ( argc && (argv->Flags & 0x1F) != 0 && ((argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt) )
    {
      Scaleform::GFx::AS3::Value::Assign(&delimiter, argv);
      Flags = delimiter.Flags;
    }
    limit = 0x7FFFFFFF;
    if ( v10 >= 2 && (v12[1].Flags & 0x1F) != 0 && ((v12[1].Flags & 0x1F) - 12 > 3 || v12[1].value.VS._1.VInt) )
    {
      if ( !Scaleform::GFx::AS3::Value::Convert2Number(
              (Scaleform::GFx::AS3::Value *)&v12[1],
              (Scaleform::GFx::AS3::CheckResult *)&vm,
              (long double *)&nlimit)->Result )
      {
        Scaleform::GFx::AS3::Value::~Value(&delimiter);
        goto LABEL_62;
      }
      pre.pObject = (Scaleform::GFx::AS3::Instances::fl::RegExp *)((unsigned __int16)vm | 0xC00);
      Flags = delimiter.Flags;
      nlimit = nlimit;
      limit = (unsigned int)nlimit.pFirst;
    }
    if ( (Flags & 0x1Fu) - 12 <= 3 && Scaleform::GFx::AS3::VM::IsOfType(v6, &delimiter, "RegExp", v6->CurrentDomain) )
    {
      VInt = (Scaleform::GFx::AS3::Instances::fl::RegExp *)delimiter.value.VS._1.VInt;
      v14 = 0;
      pre.pObject = (Scaleform::GFx::AS3::Instances::fl::RegExp *)delimiter.value.VS._1.VInt;
      if ( delimiter.value.VS._1.VInt )
      {
        ++*(_DWORD *)(delimiter.value.VS._1.VInt + 16);
        VInt->RefCount &= 0x8FBFFFFF;
      }
      VInt->IsGlobal = 1;
      pStringManager = VInt->pTraits.pObject->pVM->StringManagerRef->pStringManager;
      vm = &pStringManager->EmptyStringNode;
      ++pStringManager->EmptyStringNode.RefCount;
      Scaleform::GFx::AS3::Instances::fl::RegExp::sourceGet(VInt, (Scaleform::GFx::ASString *)&vm);
      if ( vm->Size )
      {
        pV = Scaleform::GFx::AS3::VM::MakeArray(
               v6,
               (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> *)&parr)->pV;
        parr.pObject = pV;
        next = 0;
        cnt = 0;
        while ( 1 )
        {
          v36 |= 1u;
          v40.pObject = 0;
          Scaleform::GFx::AS3::Instances::fl::RegExp::AS3exec(VInt, &v40, &str);
          pObject = v40.pObject;
          v19 = 0;
          if ( v40.pObject )
          {
            v18 = v14++;
            cnt = v14;
            if ( v18 < limit )
              v19 = 1;
          }
          if ( (v36 & 1) != 0 )
          {
            v36 &= ~1u;
            if ( v40.pObject )
            {
              if ( ((int)v40.pObject & 1) == 0 )
              {
                v20 = v40.pObject->RefCount;
                if ( ((unsigned int)&byte_3FFFFF & v20) != 0 )
                {
                  v40.pObject->RefCount = v20 - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
                }
              }
            }
          }
          if ( !v19 )
            break;
          MatchOffset = (const char *)VInt->MatchOffset;
          MatchLength = VInt->MatchLength;
          v.pNode = Scaleform::GFx::ASConstString::SubstringNode(&str, (const char *)next, MatchOffset);
          ++v.pNode->RefCount;
          Scaleform::GFx::AS3::Value::Value(&val, &v);
          Length = pV->SA.Length;
          if ( Length == pV->SA.ValueA.Data.Size )
          {
            Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
              &pV->SA.ValueA.Data,
              &val);
          }
          else
          {
            pV->SA.ValueHHighInd = Length;
            nlimit.pFirst = &pV->SA.ValueHHighInd;
            nlimit.pSecond = &val;
            Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeRef>(
              &pV->SA.ValueH.mHash,
              pV->SA.ValueH.mHash.pHeap,
              &nlimit);
          }
          ++pV->SA.Length;
          if ( (val.Flags & 0x1F) > 9 )
          {
            if ( (val.Flags & 0x200) != 0 )
              Scaleform::GFx::AS3::Value::ReleaseWeakRef(&val);
            else
              Scaleform::GFx::AS3::Value::ReleaseInternal(&val);
          }
          pNode = v.pNode;
          --v.pNode->RefCount;
          if ( !pNode->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
          v25 = (unsigned int)&MatchOffset[MatchLength];
          v14 = cnt;
          next = v25;
        }
        if ( v14 < limit )
        {
          v26 = (const char *)Scaleform::GFx::ASConstString::GetLength(&str);
          v27 = Scaleform::GFx::ASString::Substring(&str, (Scaleform::GFx::ASString *)&cnt, (const char *)next, v26);
          Scaleform::GFx::AS3::Value::Value(&val, v27);
          v28 = pV->SA.Length;
          if ( v28 == pV->SA.ValueA.Data.Size )
          {
            Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
              &pV->SA.ValueA.Data,
              &val);
          }
          else
          {
            pV->SA.ValueHHighInd = v28;
            nlimit.pFirst = &pV->SA.ValueHHighInd;
            nlimit.pSecond = &val;
            Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeRef>(
              &pV->SA.ValueH.mHash,
              pV->SA.ValueH.mHash.pHeap,
              &nlimit);
          }
          ++pV->SA.Length;
          Scaleform::GFx::AS3::Value::~Value(&val);
          v29 = (Scaleform::GFx::ASStringNode *)cnt;
          --*(_DWORD *)(cnt + 12);
          if ( !v29->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v29);
        }
        Scaleform::GFx::AS3::Value::Assign(result, pV);
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>::~SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>((Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&parr);
        v30 = vm;
        --vm->RefCount;
        if ( !v30->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v30);
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>::~SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>((Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&pre);
        Scaleform::GFx::AS3::Value::~Value(&delimiter);
        goto LABEL_62;
      }
      Scaleform::GFx::AS3::Value::Assign(&delimiter, (const Scaleform::GFx::ASString *)&vm);
      v31 = vm;
      --vm->RefCount;
      if ( !v31->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v31);
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>::~SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>((Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&pre);
      RefCount = parr.pObject;
    }
    delimStr.pNode = (Scaleform::GFx::ASStringNode *)(RefCount[2].SA.ValueA.Data.Policy.Capacity + 32);
    ++delimStr.pNode->RefCount;
    if ( Scaleform::GFx::AS3::Value::Convert2String(&delimiter, (Scaleform::GFx::AS3::CheckResult *)&vm, &delimStr)->Result )
    {
      v32 = (Scaleform::GFx::AS3::Object **)Scaleform::GFx::AS3::InstanceTraits::fl::String::StringSplit(
                                              (Scaleform::String)&vm,
                                              v6,
                                              &str,
                                              (Scaleform::GFx::ASStringNode *)delimStr.pNode->pData,
                                              limit);
      Scaleform::GFx::AS3::Value::Pick(result, *v32);
    }
    v33 = delimStr.pNode;
    --delimStr.pNode->RefCount;
    if ( !v33->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v33);
    if ( (delimiter.Flags & 0x1F) > 9 )
    {
      if ( (delimiter.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&delimiter);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&delimiter);
    }
LABEL_62:
    v34 = str.pNode;
    --str.pNode->RefCount;
    v9 = v34;
    if ( v34->RefCount )
      return;
    goto LABEL_63;
  }
  v8 = str.pNode;
  --str.pNode->RefCount;
  v9 = v8;
  if ( v8->RefCount )
    return;
LABEL_63:
  Scaleform::GFx::ASStringNode::ReleaseNode(v9);
}
