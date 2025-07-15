void __thiscall Scaleform::GFx::AS3ValueObjectInterface::VisitMembers(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        Scaleform::GFx::ASStringNode *pdata,
        Scaleform::GFx::Value::ObjectInterface::ObjVisitor *visitor,
        bool isdobj)
{
  Scaleform::GFx::AMP::ViewStats *v5; // eax
  Scaleform::GFx::MovieImpl *pMovieRoot; // eax
  Scaleform::GFx::ASStringNode *v7; // esi
  Scaleform::GFx::ASStringNode *v8; // edx
  const char *v9; // ecx
  unsigned int v10; // eax
  unsigned int v11; // esi
  _DWORD *v12; // ecx
  Scaleform::GFx::ASStringNode *v13; // ebp
  signed int v14; // esi
  const char *v15; // eax
  const char *v16; // edi
  unsigned int v17; // eax
  const char *v18; // ecx
  unsigned int Size; // ebp
  unsigned int v20; // eax
  int v21; // ecx
  unsigned int v22; // ebp
  int v23; // edi
  Scaleform::GFx::ASStringNode *SlotNameNode; // esi
  int v25; // ebx
  Scaleform::GFx::AS3::SlotInfo *SlotInfo; // eax
  int v27; // ecx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  bool v29; // zf
  unsigned int v30; // eax
  const char *v31; // ecx
  const char *v32; // eax
  int v33; // ecx
  int v34; // eax
  int v35; // ebp
  Scaleform::GFx::DisplayObjContainer *v36; // ecx
  unsigned int i; // edi
  Scaleform::GFx::DisplayObjectBase *ChildAt; // eax
  Scaleform::GFx::DisplayObjectBase_vtbl **v39; // esi
  Scaleform::GFx::DisplayObjectBase_vtbl *v40; // eax
  Scaleform::GFx::DisplayObjectBase_vtbl *v41; // ecx
  Scaleform::GFx::AS3::Value::V1U v42; // esi
  unsigned int v43; // edx
  Scaleform::GFx::AS3::WeakProxy *v44; // eax
  Scaleform::GFx::ASStringNode *v45; // eax
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v47; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::GFx::AS3::CheckResult result[4]; // [esp+18h] [ebp-40h] BYREF
  Scaleform::GFx::AS3::MovieRoot *root; // [esp+1Ch] [ebp-3Ch]
  Scaleform::GFx::AS3::Value asval; // [esp+20h] [ebp-38h] BYREF
  Scaleform::AmpFunctionTimer _amp_timer_Amp_Native_Function_Id_ObjectInterface_VisitMembers; // [esp+30h] [ebp-28h] BYREF
  Scaleform::GFx::Value val; // [esp+40h] [ebp-18h] BYREF

  v5 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &_amp_timer_Amp_Native_Function_Id_ObjectInterface_VisitMembers,
    v5,
    "ObjectInterface::VisitMembers",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_VisitMembers);
  pMovieRoot = this->pMovieRoot;
  v7 = pdata;
  v8 = pdata + 1;
  root = (Scaleform::GFx::AS3::MovieRoot *)pMovieRoot->pASMovieRoot.pObject;
  if ( pdata != (Scaleform::GFx::ASStringNode *)-24 )
  {
    v9 = v8->pData;
    if ( v8->pData )
    {
      v11 = *((_DWORD *)v9 + 1);
      v10 = 0;
      v12 = v9 + 8;
      do
      {
        if ( *v12 != -2 )
          break;
        ++v10;
        v12 += 8;
      }
      while ( v10 <= v11 );
    }
    else
    {
      v8 = 0;
      v10 = 0;
    }
    v13 = v8;
    v14 = v10;
    while ( v13 )
    {
      v15 = v13->pData;
      if ( !v13->pData || v14 > *((_DWORD *)v15 + 1) )
        break;
      v16 = &v15[32 * v14];
      val.pObjectInterface = 0;
      val.Type = VT_Undefined;
      Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(
        root,
        (Scaleform::GFx::AS3::Value *)(v16 + 24),
        (Scaleform::GFx::ASStringNode *)&val);
      visitor->Visit(visitor, (const char *)**((_DWORD **)v16 + 5), &val);
      if ( (val.Type & 0x40) != 0 )
        val.pObjectInterface->ObjectRelease(val.pObjectInterface, &val, (void *)val.mValue.IValue);
      v17 = *((_DWORD *)v13->pData + 1);
      if ( v14 <= (int)v17 && ++v14 <= v17 )
      {
        v18 = &v13->pData[32 * v14 + 8];
        do
        {
          if ( *(_DWORD *)v18 != -2 )
            break;
          ++v14;
          v18 += 32;
        }
        while ( v14 <= v17 );
      }
    }
    v7 = pdata;
  }
  if ( visitor->IncludeAS3PublicMembers(visitor) )
  {
    Size = v7->Size;
    v20 = *(_DWORD *)(Size + 20);
    v21 = *(_DWORD *)(Size + 32);
    v22 = Size + 20;
    v23 = 0;
    if ( v20 + v21 )
    {
      while ( 1 )
      {
        val.pObjectInterface = 0;
        val.Type = VT_Undefined;
        if ( v23 >= 0 && v23 >= v20 )
          SlotNameNode = *(Scaleform::GFx::ASStringNode **)(32 * (v23 - v20) + *(_DWORD *)(v22 + 8));
        else
          SlotNameNode = Scaleform::GFx::AS3::Slots::GetSlotNameNode(
                           *(Scaleform::GFx::AS3::Slots **)(v22 + 4),
                           (Scaleform::GFx::AS3::AbsoluteIndex)v23);
        v25 = SlotNameNode->RefCount + 1;
        SlotNameNode->RefCount = v25;
        if ( v23 >= 0 && (unsigned int)v23 >= *(_DWORD *)v22 )
          SlotInfo = (Scaleform::GFx::AS3::SlotInfo *)(32 * (v23 - *(_DWORD *)v22) + *(_DWORD *)(v22 + 8) + 8);
        else
          SlotInfo = (Scaleform::GFx::AS3::SlotInfo *)Scaleform::GFx::AS3::Slots::GetSlotInfo(
                                                        *(Scaleform::GFx::AS3::Slots **)(v22 + 4),
                                                        (Scaleform::GFx::AS3::AbsoluteIndex)v23);
        v27 = (int)(*(_DWORD *)SlotInfo << 22) >> 27;
        if ( v27 == 11 || v27 > 12 )
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
          v29 = SlotNameNode->RefCount-- == 1;
          if ( v29 )
            Scaleform::GFx::ASStringNode::ReleaseNode(SlotNameNode);
          v29 = (val.Type & 0x40) == 0;
          goto LABEL_49;
        }
        SlotNameNode->RefCount = v25 - 1;
        if ( v25 == 1 )
          Scaleform::GFx::ASStringNode::ReleaseNode(SlotNameNode);
        if ( (val.Type & 0x40) == 0 )
          goto LABEL_51;
LABEL_50:
        val.pObjectInterface->ObjectRelease(val.pObjectInterface, &val, (void *)val.mValue.IValue);
LABEL_51:
        if ( v23 < 0 || v23 < (unsigned int)(*(_DWORD *)(v22 + 12) + *(_DWORD *)v22) )
          ++v23;
        v20 = *(_DWORD *)v22;
        if ( v23 >= (unsigned int)(*(_DWORD *)v22 + *(_DWORD *)(v22 + 12)) )
        {
          v7 = pdata;
          goto LABEL_56;
        }
      }
      SlotNameNode->RefCount = v25 - 1;
      if ( v25 == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(SlotNameNode);
      v29 = (val.Type & 0x40) == 0;
LABEL_49:
      if ( v29 )
        goto LABEL_51;
      goto LABEL_50;
    }
  }
LABEL_56:
  v30 = v7->Size;
  if ( (unsigned int)(*(_DWORD *)(v30 + 60) - 23) < 6 && (*(_DWORD *)(v30 + 56) & 0x20) == 0 )
  {
    v31 = v7[2].pData;
    v32 = (*((_WORD *)v31 + 31) & 0x200) != 0 ? v31 : 0;
    if ( v32
      && (v33 = *((*((_WORD *)v31 + 31) & 0x200) != 0 ? (unsigned __int8 *)(v31 + 65) : (unsigned __int8 *)65),
          (v34 = (*(int (__thiscall **)(const char *))(*(_DWORD *)&v32[4 * v33] + 20))(&v32[4 * v33])) != 0) )
    {
      v35 = v34 - 36;
    }
    else
    {
      v35 = 0;
    }
    v36 = *(Scaleform::GFx::DisplayObjContainer **)(v35 + 12);
    for ( i = 0; i < v36->mDisplayList.DisplayObjectArray.Data.Size; ++i )
    {
      ChildAt = Scaleform::GFx::DisplayObjContainer::GetChildAt(v36, i);
      if ( ChildAt )
      {
        v39 = &ChildAt->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
            + ChildAt->AvmObjOffset;
        ((void (__thiscall *)(Scaleform::GFx::DisplayObjectBase_vtbl **, int))(*v39)->GetRatio)(v39, 1);
        v40 = v39[2];
        if ( !v40 )
          v40 = v39[1];
        v41 = v40;
        if ( ((unsigned __int8)v40 & 1) != 0 )
          v41 = (Scaleform::GFx::DisplayObjectBase_vtbl *)((char *)v40 - 1);
        v42.VInt = (int)v41;
        if ( v41 )
        {
          v43 = ((int)v41->GetMatrix3D + 1) & 0x8FBFFFFF;
          v41->GetMatrix3D = (const Scaleform::Render::Matrix3x4<float> *(__thiscall *)(Scaleform::GFx::DisplayObjectBase *))v43;
          if ( ((unsigned __int8)v41 & 1) == 0 && (v43 & 0x3FFFFF) != 0 )
          {
            v41->GetMatrix3D = (const Scaleform::Render::Matrix3x4<float> *(__thiscall *)(Scaleform::GFx::DisplayObjectBase *))(v43 - 1);
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v41);
          }
        }
      }
      else
      {
        v42.VInt = 0;
      }
      Scaleform::GFx::DisplayObject::GetName(
        *(Scaleform::GFx::DisplayObject **)(v42.VInt + 48),
        (Scaleform::GFx::ASString *)&pdata);
      *(_DWORD *)(v42.VInt + 16) = (*(_DWORD *)(v42.VInt + 16) + 1) & 0x8FBFFFFF;
      asval.Flags = 12;
      asval.Bonus.pWeakProxy = 0;
      asval.value.VS._1 = v42;
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
          v44 = asval.Bonus.pWeakProxy;
          --asval.Bonus.pWeakProxy->RefCount;
          if ( !v44->RefCount )
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v44);
          asval.Flags &= 0xFFFFFDE0;
          memset(&asval.Bonus, 0, 12);
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&asval);
        }
      }
      v45 = pdata;
      --pdata->RefCount;
      if ( !v45->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v45);
      v36 = *(Scaleform::GFx::DisplayObjContainer **)(v35 + 12);
    }
  }
  Stats = _amp_timer_Amp_Native_Function_Id_ObjectInterface_VisitMembers.Stats;
  if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_VisitMembers.Stats )
  {
    v47 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_VisitMembers.Stats->__vftable;
    ProfileTicks = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v47->NativePopCallstack)(
      Stats,
      ProfileTicks - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_VisitMembers.StartTicks),
      (ProfileTicks - _amp_timer_Amp_Native_Function_Id_ObjectInterface_VisitMembers.StartTicks) >> 32);
  }
}
