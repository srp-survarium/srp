void __thiscall Scaleform::GFx::AS3::Instances::fl::RegExp::AS3exec(
        Scaleform::GFx::AS3::Instances::fl::RegExp *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> *result,
        const Scaleform::GFx::ASString *s)
{
  Scaleform::GFx::AS3::Instances::fl::RegExp *v3; // ebp
  int LastIndex; // eax
  int v5; // esi
  int v6; // esi
  const char *pData; // edi
  signed int Length; // eax
  int v9; // ecx
  int v10; // eax
  Scaleform::GFx::AS3::Traits *pObject; // edx
  int v12; // ecx
  Scaleform::GFx::AS3::VM *pVM; // ecx
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // edi
  Scaleform::GFx::AS3::Instances::fl::Array *pV; // ebx
  char *v16; // esi
  int v17; // eax
  unsigned int v18; // esi
  Scaleform::GFx::ASStringManager *pStringManager; // ecx
  Scaleform::GFx::AS3::Value *v20; // eax
  unsigned int v21; // ecx
  __int16 Flags; // ax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringManager *v24; // ecx
  Scaleform::GFx::ASStringNode *v25; // eax
  Scaleform::GFx::AS3::Value *Undefined; // eax
  unsigned int v27; // ecx
  const Scaleform::GFx::AS3::Value *v28; // eax
  Scaleform::GFx::ASStringNode *v29; // eax
  Scaleform::GFx::ASStringNode *v30; // eax
  char *v31; // eax
  char *v32; // esi
  const char *v33; // edx
  int v34; // eax
  int v35; // ecx
  unsigned int v36; // esi
  Scaleform::GFx::ASStringManager *v37; // ecx
  Scaleform::GFx::ASStringNode *v38; // eax
  Scaleform::GFx::ASStringNode *v39; // eax
  bool v40; // cc
  int v41; // eax
  Scaleform::GFx::AS3::Instances::fl::Object *v42; // ecx
  unsigned int RefCount; // eax
  unsigned int v44; // eax
  Scaleform::GFx::AS3::Instances::fl::Object *v45; // ecx
  unsigned int v46; // eax
  Scaleform::GFx::ASString v; // [esp+10h] [ebp-9D4h] BYREF
  int matchCount; // [esp+14h] [ebp-9D0h] BYREF
  char *nameTable; // [esp+18h] [ebp-9CCh] BYREF
  const char *subject; // [esp+1Ch] [ebp-9C8h]
  Scaleform::GFx::AS3::Value v51; // [esp+20h] [ebp-9C4h] BYREF
  int nameEntrySize; // [esp+30h] [ebp-9B4h] BYREF
  Scaleform::GFx::AS3::Value *v53; // [esp+34h] [ebp-9B0h]
  int MatchOffset; // [esp+38h] [ebp-9ACh]
  int i; // [esp+40h] [ebp-9A4h]
  int nameCount[2]; // [esp+44h] [ebp-9A0h] BYREF
  Scaleform::GFx::AS3::Instances::fl::RegExp *v57; // [esp+4Ch] [ebp-998h]
  int oldLastIndex; // [esp+50h] [ebp-994h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> v59; // [esp+54h] [ebp-990h] BYREF
  int outputVector[99]; // [esp+58h] [ebp-98Ch] BYREF
  char value[1024]; // [esp+1E4h] [ebp-800h] BYREF
  char name[1024]; // [esp+5E4h] [ebp-400h] BYREF

  v3 = this;
  LastIndex = this->LastIndex;
  v5 = -this->IsGlobal;
  this->MatchLength = 0;
  this->MatchOffset = 0;
  oldLastIndex = LastIndex;
  v6 = LastIndex & v5;
  pData = s->pNode->pData;
  v57 = this;
  subject = pData;
  Length = Scaleform::GFx::ASConstString::GetLength(&s->Scaleform::GFx::ASConstString);
  v9 = 0;
  if ( v6 >= 0 && v6 <= Length )
  {
    v10 = pcre_exec(v3->CompRegExp, 0, pData, Length, v6, 0, outputVector, 99);
    matchCount = v10;
    if ( v10 >= 0 )
    {
      pObject = v3->pTraits.pObject;
      v12 = outputVector[1] - outputVector[0];
      v3->MatchOffset = outputVector[0];
      v3->MatchLength = v12;
      pVM = pObject->pVM;
      StringManagerRef = pVM->StringManagerRef;
      pV = Scaleform::GFx::AS3::VM::MakeArray(pVM, &v59)->pV;
      v16 = 0;
      for ( nameTable = 0; (int)v16 < matchCount; nameTable = v16 )
      {
        v17 = outputVector[2 * (_DWORD)v16];
        if ( v17 <= -1 )
        {
          Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
          v27 = pV->SA.Length;
          if ( v27 == pV->SA.ValueA.Data.Size )
          {
            Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
              &pV->SA.ValueA.Data,
              Undefined);
          }
          else
          {
            pV->SA.ValueHHighInd = v27;
            nameCount[0] = (int)&pV->SA.ValueHHighInd;
            nameCount[1] = (int)Undefined;
            Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeRef>(
              &pV->SA.ValueH.mHash,
              pV->SA.ValueH.mHash.pHeap,
              (const Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeRef *)nameCount);
          }
          ++pV->SA.Length;
        }
        else
        {
          v18 = outputVector[2 * (_DWORD)v16 + 1] - v17;
          strncpy_s(value, 0x400u, &subject[v17], v18);
          pStringManager = StringManagerRef->pStringManager;
          value[v18] = 0;
          v.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(pStringManager, value);
          ++v.pNode->RefCount;
          Scaleform::GFx::AS3::Value::Value(&v51, &v);
          v21 = pV->SA.Length;
          if ( v21 == pV->SA.ValueA.Data.Size )
          {
            Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
              &pV->SA.ValueA.Data,
              v20);
          }
          else
          {
            pV->SA.ValueHHighInd = v21;
            nameEntrySize = (int)&pV->SA.ValueHHighInd;
            v53 = v20;
            Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeRef>(
              &pV->SA.ValueH.mHash,
              pV->SA.ValueH.mHash.pHeap,
              (const Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeRef *)&nameEntrySize);
          }
          Flags = v51.Flags;
          ++pV->SA.Length;
          if ( (Flags & 0x1Fu) > 9 )
          {
            if ( (Flags & 0x200) != 0 )
              Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v51);
            else
              Scaleform::GFx::AS3::Value::ReleaseInternal(&v51);
          }
          pNode = v.pNode;
          --v.pNode->RefCount;
          if ( !pNode->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
          v16 = nameTable;
        }
        ++v16;
      }
      MatchOffset = v3->MatchOffset;
      v24 = StringManagerRef->pStringManager;
      nameEntrySize = 2;
      v53 = 0;
      v.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(v24, (char *)&stru_962594.m_gs_ids);
      ++v.pNode->RefCount;
      Scaleform::GFx::AS3::Object::AddDynamicSlotValuePair(
        pV,
        &v,
        (const Scaleform::GFx::AS3::Value *)&nameEntrySize,
        aNone);
      v25 = v.pNode;
      --v.pNode->RefCount;
      if ( !v25->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v25);
      if ( (nameEntrySize & 0x1Fu) > 9 )
      {
        if ( (nameEntrySize & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef((Scaleform::GFx::AS3::Value *)&nameEntrySize);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&nameEntrySize);
      }
      matchCount = (int)Scaleform::GFx::ASStringManager::CreateStringNode(
                          StringManagerRef->pStringManager,
                          (char *)subject);
      ++*(_DWORD *)(matchCount + 12);
      v.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(StringManagerRef->pStringManager, "input");
      ++v.pNode->RefCount;
      Scaleform::GFx::AS3::Value::Value(&v51, (const Scaleform::GFx::ASString *)&matchCount);
      Scaleform::GFx::AS3::Object::AddDynamicSlotValuePair(pV, &v, v28, aNone);
      v29 = v.pNode;
      --v.pNode->RefCount;
      if ( !v29->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v29);
      if ( (v51.Flags & 0x1F) > 9 )
      {
        if ( (v51.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v51);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v51);
      }
      v30 = (Scaleform::GFx::ASStringNode *)matchCount;
      --*(_DWORD *)(matchCount + 12);
      if ( !v30->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v30);
      if ( v3->HasNamedGroups )
      {
        pcre_fullinfo(v3->CompRegExp, 0, 8, nameCount);
        pcre_fullinfo(v3->CompRegExp, 0, 7, &nameEntrySize);
        pcre_fullinfo(v3->CompRegExp, 0, 9, &nameTable);
        i = 0;
        if ( nameCount[0] > 0 )
        {
          v31 = nameTable;
          do
          {
            strncpy_s(name, 0x400u, v31 + 2, strlen(v31 + 2));
            v32 = nameTable;
            v33 = subject;
            name[strlen(nameTable + 2)] = 0;
            v34 = v32[1] + (*v32 << 8);
            v35 = outputVector[2 * v34];
            v36 = outputVector[2 * v34 + 1] - v35;
            strncpy_s(value, 0x400u, &v33[v35], v36);
            v37 = StringManagerRef->pStringManager;
            value[v36] = 0;
            matchCount = (int)Scaleform::GFx::ASStringManager::CreateStringNode(v37, value);
            ++*(_DWORD *)(matchCount + 12);
            Scaleform::GFx::AS3::Value::Value(&v51, (const Scaleform::GFx::ASString *)&matchCount);
            v.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(StringManagerRef->pStringManager, name);
            ++v.pNode->RefCount;
            Scaleform::GFx::AS3::Object::AddDynamicSlotValuePair(pV, &v, &v51, aNone);
            v38 = v.pNode;
            --v.pNode->RefCount;
            if ( !v38->RefCount )
              Scaleform::GFx::ASStringNode::ReleaseNode(v38);
            if ( (v51.Flags & 0x1F) > 9 )
            {
              if ( (v51.Flags & 0x200) != 0 )
                Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v51);
              else
                Scaleform::GFx::AS3::Value::ReleaseInternal(&v51);
            }
            v39 = (Scaleform::GFx::ASStringNode *)matchCount;
            --*(_DWORD *)(matchCount + 12);
            if ( !v39->RefCount )
              Scaleform::GFx::ASStringNode::ReleaseNode(v39);
            v31 = &nameTable[nameEntrySize];
            v40 = i + 1 < nameCount[0];
            nameTable += nameEntrySize;
            ++i;
          }
          while ( v40 );
          v3 = v57;
        }
      }
      if ( v3->IsGlobal )
        v3->LastIndex = v3->MatchOffset + v3->MatchLength;
      v41 = v3->LastIndex;
      if ( v41 == oldLastIndex )
        v3->LastIndex = v41 + 1;
      if ( pV != result->pObject )
      {
        if ( pV )
          pV->RefCount = (pV->RefCount + 1) & 0x8FBFFFFF;
        v42 = result->pObject;
        if ( result->pObject )
        {
          if ( ((unsigned __int8)v42 & 1) != 0 )
          {
            result->pObject = (Scaleform::GFx::AS3::Instances::fl::Object *)((char *)v42 - 1);
          }
          else
          {
            RefCount = v42->RefCount;
            if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
            {
              v42->RefCount = RefCount - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v42);
            }
          }
        }
        result->pObject = pV;
      }
      if ( pV && ((unsigned __int8)pV & 1) == 0 )
      {
        v44 = pV->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & v44) != 0 )
        {
          pV->RefCount = v44 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pV);
        }
      }
      return;
    }
    v9 = v10;
  }
  v3->MatchOffset = v9;
  v45 = result->pObject;
  if ( result->pObject )
  {
    if ( ((unsigned __int8)v45 & 1) != 0 )
    {
      result->pObject = (Scaleform::GFx::AS3::Instances::fl::Object *)((char *)v45 - 1);
      result->pObject = 0;
    }
    else
    {
      v46 = v45->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & v46) != 0 )
      {
        v45->RefCount = v46 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v45);
      }
      result->pObject = 0;
    }
  }
}
