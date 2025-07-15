void __thiscall Scaleform::GFx::AS3ValueObjectInterface::VisitMembers(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        Scaleform::GFx::ASStringNode *pdata,
        Scaleform::GFx::Value::ObjectInterface::ObjVisitor *visitor,
        bool isdobj)
{
  Scaleform::GFx::ASStringNode *v4; // esi
  Scaleform::GFx::ASStringNode *v5; // edx
  const char *v6; // ecx
  unsigned int v7; // eax
  unsigned int v8; // esi
  _DWORD *v9; // ecx
  Scaleform::GFx::ASStringNode *v10; // ebp
  signed int v11; // esi
  const char *v12; // eax
  const char *v13; // edi
  unsigned int v14; // eax
  const char *v15; // ecx
  unsigned int Size; // ebp
  unsigned int v17; // ecx
  int v18; // eax
  unsigned int v19; // ebp
  int v20; // edi
  Scaleform::GFx::ASStringNode *SlotNameNode; // esi
  int v22; // ebx
  Scaleform::GFx::AS3::SlotInfo *SlotInfo; // eax
  int v24; // ecx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  bool v26; // zf
  unsigned int v27; // eax
  const char *v28; // ecx
  const char *v29; // eax
  int v30; // ecx
  int v31; // eax
  int v32; // ebp
  Scaleform::GFx::DisplayObjContainer *v33; // ecx
  unsigned int i; // edi
  Scaleform::GFx::DisplayObjectBase *ChildAt; // eax
  Scaleform::GFx::DisplayObjectBase_vtbl **v36; // esi
  Scaleform::GFx::DisplayObjectBase_vtbl *v37; // eax
  Scaleform::GFx::DisplayObjectBase_vtbl *v38; // ecx
  Scaleform::GFx::AS3::Value::V1U v39; // esi
  unsigned int v40; // edx
  Scaleform::GFx::AS3::WeakProxy *v41; // eax
  Scaleform::GFx::ASStringNode *v42; // eax
  Scaleform::GFx::AS3::CheckResult result[4]; // [esp+18h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::MovieRoot *root; // [esp+1Ch] [ebp-2Ch]
  Scaleform::GFx::AS3::Value asval; // [esp+20h] [ebp-28h] BYREF
  Scaleform::GFx::Value val; // [esp+30h] [ebp-18h] BYREF

  v4 = pdata;
  v5 = pdata + 1;
  root = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  if ( pdata != (Scaleform::GFx::ASStringNode *)-24 )
  {
    v6 = v5->pData;
    if ( v5->pData )
    {
      v8 = *((_DWORD *)v6 + 1);
      v7 = 0;
      v9 = v6 + 8;
      do
      {
        if ( *v9 != -2 )
          break;
        ++v7;
        v9 += 8;
      }
      while ( v7 <= v8 );
    }
    else
    {
      v5 = 0;
      v7 = 0;
    }
    v10 = v5;
    v11 = v7;
    while ( v10 )
    {
      v12 = v10->pData;
      if ( !v10->pData || v11 > *((_DWORD *)v12 + 1) )
        break;
      v13 = &v12[32 * v11];
      val.pObjectInterface = 0;
      val.Type = VT_Undefined;
      Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(
        root,
        (Scaleform::GFx::AS3::Value *)(v13 + 24),
        (Scaleform::GFx::ASStringNode *)&val);
      visitor->Visit(visitor, (const char *)**((_DWORD **)v13 + 5), &val);
      if ( (val.Type & 0x40) != 0 )
        val.pObjectInterface->ObjectRelease(val.pObjectInterface, &val, (void *)val.mValue.IValue);
      v14 = *((_DWORD *)v10->pData + 1);
      if ( v11 <= (int)v14 && ++v11 <= v14 )
      {
        v15 = &v10->pData[32 * v11 + 8];
        do
        {
          if ( *(_DWORD *)v15 != -2 )
            break;
          ++v11;
          v15 += 32;
        }
        while ( v11 <= v14 );
      }
    }
    v4 = pdata;
  }
  if ( visitor->IncludeAS3PublicMembers(visitor) )
  {
    Size = v4->Size;
    v17 = *(_DWORD *)(Size + 20);
    v18 = *(_DWORD *)(Size + 32);
    v19 = Size + 20;
    v20 = 0;
    if ( v17 + v18 )
    {
      while ( 1 )
      {
        val.pObjectInterface = 0;
        val.Type = VT_Undefined;
        if ( v20 >= 0 && v20 >= v17 )
          SlotNameNode = *(Scaleform::GFx::ASStringNode **)(*(_DWORD *)(v19 + 8) + 28 * (v20 - v17));
        else
          SlotNameNode = Scaleform::GFx::AS3::Slots::GetSlotNameNode(
                           *(Scaleform::GFx::AS3::Slots **)(v19 + 4),
                           (Scaleform::GFx::AS3::AbsoluteIndex)v20);
        v22 = SlotNameNode->RefCount + 1;
        SlotNameNode->RefCount = v22;
        if ( v20 >= 0 && (unsigned int)v20 >= *(_DWORD *)v19 )
          SlotInfo = (Scaleform::GFx::AS3::SlotInfo *)(*(_DWORD *)(v19 + 8) + 28 * (v20 - *(_DWORD *)v19) + 8);
        else
          SlotInfo = (Scaleform::GFx::AS3::SlotInfo *)Scaleform::GFx::AS3::Slots::GetSlotInfo(
                                                        *(Scaleform::GFx::AS3::Slots **)(v19 + 4),
                                                        (Scaleform::GFx::AS3::AbsoluteIndex)v20);
        v24 = (int)(*(_DWORD *)SlotInfo << 22) >> 27;
        if ( v24 == 11 || v24 > 12 )
          break;
        if ( (*((_BYTE *)SlotInfo->pNs.pObject + 20) & 0xF) == 0 )
        {
          asval.Flags = 0;
          asval.Bonus.pWeakProxy = 0;
          Scaleform::GFx::AS3::SlotInfo::GetSlotValueUnsafe(SlotInfo, &result[3], &asval, pdata);
          Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(root, &asval, (Scaleform::GFx::ASStringNode *)&val);
          visitor->Visit(visitor, SlotNameNode->pData, &val);
          if ( (asval.Flags & 0x1F) > 9 )
          {
            if ( (asval.Flags & 0x200) != 0 )
            {
              pWeakProxy = asval.Bonus.pWeakProxy;
              --asval.Bonus.pWeakProxy->RefCount;
              if ( !pWeakProxy->RefCount )
                Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
              asval.Flags &= 0xFFFFFDE0;
              memset(&asval.Bonus, 0, 12);
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(&asval);
            }
          }
          v26 = SlotNameNode->RefCount-- == 1;
          if ( v26 )
            Scaleform::GFx::ASStringNode::ReleaseNode(SlotNameNode);
          v26 = (val.Type & 0x40) == 0;
          goto LABEL_49;
        }
        SlotNameNode->RefCount = v22 - 1;
        if ( v22 == 1 )
          Scaleform::GFx::ASStringNode::ReleaseNode(SlotNameNode);
        if ( (val.Type & 0x40) == 0 )
          goto LABEL_51;
LABEL_50:
        val.pObjectInterface->ObjectRelease(val.pObjectInterface, &val, (void *)val.mValue.IValue);
LABEL_51:
        if ( v20 < 0 || v20 < (unsigned int)(*(_DWORD *)(v19 + 12) + *(_DWORD *)v19) )
          ++v20;
        v17 = *(_DWORD *)v19;
        if ( v20 >= (unsigned int)(*(_DWORD *)v19 + *(_DWORD *)(v19 + 12)) )
        {
          v4 = pdata;
          goto LABEL_56;
        }
      }
      SlotNameNode->RefCount = v22 - 1;
      if ( v22 == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(SlotNameNode);
      v26 = (val.Type & 0x40) == 0;
LABEL_49:
      if ( v26 )
        goto LABEL_51;
      goto LABEL_50;
    }
  }
LABEL_56:
  v27 = v4->Size;
  if ( (unsigned int)(*(_DWORD *)(v27 + 60) - 23) < 6 && (*(_DWORD *)(v27 + 56) & 0x20) == 0 )
  {
    v28 = v4[2].pData;
    v29 = (*((_WORD *)v28 + 31) & 0x200) != 0 ? v28 : 0;
    if ( v29
      && (v30 = *((*((_WORD *)v28 + 31) & 0x200) != 0 ? (unsigned __int8 *)(v28 + 65) : (unsigned __int8 *)65),
          (v31 = (*(int (__thiscall **)(const char *))(*(_DWORD *)&v29[4 * v30] + 20))(&v29[4 * v30])) != 0) )
    {
      v32 = v31 - 36;
    }
    else
    {
      v32 = 0;
    }
    v33 = *(Scaleform::GFx::DisplayObjContainer **)(v32 + 12);
    for ( i = 0; i < v33->mDisplayList.DisplayObjectArray.Data.Size; ++i )
    {
      ChildAt = Scaleform::GFx::DisplayObjContainer::GetChildAt(v33, i);
      if ( ChildAt )
      {
        v36 = &ChildAt->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
            + ChildAt->AvmObjOffset;
        ((void (__thiscall *)(Scaleform::GFx::DisplayObjectBase_vtbl **, int))(*v36)->GetRatio)(v36, 1);
        v37 = v36[2];
        if ( !v37 )
          v37 = v36[1];
        v38 = v37;
        if ( ((unsigned __int8)v37 & 1) != 0 )
          v38 = (Scaleform::GFx::DisplayObjectBase_vtbl *)((char *)v37 - 1);
        v39.VInt = (int)v38;
        if ( v38 )
        {
          v40 = ((int)v38->GetMatrix3D + 1) & 0x8FBFFFFF;
          v38->GetMatrix3D = (const Scaleform::Render::Matrix3x4<float> *(__thiscall *)(Scaleform::GFx::DisplayObjectBase *))v40;
          if ( ((unsigned __int8)v38 & 1) == 0 && ((unsigned int)&byte_3FFFFF & v40) != 0 )
          {
            v38->GetMatrix3D = (const Scaleform::Render::Matrix3x4<float> *(__thiscall *)(Scaleform::GFx::DisplayObjectBase *))(v40 - 1);
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v38);
          }
        }
      }
      else
      {
        v39.VInt = 0;
      }
      Scaleform::GFx::DisplayObject::GetName(
        *(Scaleform::GFx::DisplayObject **)(v39.VInt + 48),
        (Scaleform::GFx::ASString *)&pdata);
      *(_DWORD *)(v39.VInt + 16) = (*(_DWORD *)(v39.VInt + 16) + 1) & 0x8FBFFFFF;
      asval.Flags = 12;
      asval.Bonus.pWeakProxy = 0;
      asval.value.VS._1 = v39;
      val.pObjectInterface = 0;
      val.Type = VT_Undefined;
      Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(root, &asval, (Scaleform::GFx::ASStringNode *)&val);
      visitor->Visit(visitor, pdata->pData, &val);
      if ( (val.Type & 0x40) != 0 )
      {
        val.pObjectInterface->ObjectRelease(val.pObjectInterface, &val, (void *)val.mValue.IValue);
        val.pObjectInterface = 0;
      }
      val.Type = VT_Undefined;
      if ( (asval.Flags & 0x1F) > 9 )
      {
        if ( (asval.Flags & 0x200) != 0 )
        {
          v41 = asval.Bonus.pWeakProxy;
          --asval.Bonus.pWeakProxy->RefCount;
          if ( !v41->RefCount )
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v41);
          asval.Flags &= 0xFFFFFDE0;
          memset(&asval.Bonus, 0, 12);
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&asval);
        }
      }
      v42 = pdata;
      --pdata->RefCount;
      if ( !v42->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v42);
      v33 = *(Scaleform::GFx::DisplayObjContainer **)(v32 + 12);
    }
  }
}
