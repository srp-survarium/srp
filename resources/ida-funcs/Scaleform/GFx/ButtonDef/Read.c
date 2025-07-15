void __thiscall Scaleform::GFx::ButtonDef::Read(
        Scaleform::GFx::ButtonDef *this,
        Scaleform::GFx::LoadProcess *p,
        Scaleform::GFx::TagType tagType)
{
  Scaleform::GFx::ButtonDef *v3; // esi
  Scaleform::GFx::LoadProcess *v4; // edi
  Scaleform::ArrayDataBase<Scaleform::GFx::ButtonRecord,Scaleform::AllocatorLH<Scaleform::GFx::ButtonRecord,258>,Scaleform::ArrayDefaultPolicy> *p_Data; // ebx
  unsigned int v6; // edi
  unsigned __int16 *p_Depth; // eax
  unsigned int Size; // eax
  unsigned int v9; // esi
  Scaleform::RefCountVImpl **p_pFilters; // ecx
  Scaleform::RefCountVImpl *v11; // ecx
  bool v12; // zf
  unsigned int v13; // eax
  Scaleform::GFx::ButtonRecord *v14; // edi
  Scaleform::GFx::ASSupport *pObject; // ecx
  Scaleform::GFx::AudioBase *v16; // ecx
  int v17; // eax
  int U16; // ebx
  Scaleform::GFx::SWFProcessInfo *pAltStream; // eax
  int v20; // edx
  unsigned int v21; // edx
  unsigned int v22; // eax
  unsigned __int16 *v23; // ecx
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // ecx
  unsigned int v25; // [esp+19Ch] [ebp-70h]
  Scaleform::RefCountVImpl **v26; // [esp+1A0h] [ebp-6Ch]
  int pos; // [esp+1A4h] [ebp-68h]
  int posa; // [esp+1A4h] [ebp-68h]
  Scaleform::GFx::ButtonRecord __that; // [esp+1ACh] [ebp-60h] BYREF

  v3 = this;
  switch ( tagType )
  {
    case Tag_ButtonCharacter:
      __that.ButtonMatrix.M[0][0] = 1.0;
      __that.ButtonMatrix.M[0][1] = 0.0;
      __that.ButtonMatrix.M[0][2] = 0.0;
      __that.ButtonMatrix.M[0][3] = 0.0;
      __that.ButtonMatrix.M[1][0] = 0.0;
      __that.ButtonMatrix.M[1][2] = 0.0;
      __that.ButtonMatrix.M[1][3] = 0.0;
      __that.ButtonMatrix.M[1][1] = 1.0;
      Scaleform::Render::Cxform::Cxform(&__that.ButtonCxform);
      v4 = p;
      __that.pFilters.pObject = 0;
      __that.CharacterId.Id = 0x40000;
      __that.Flags = 0;
      if ( !Scaleform::GFx::ButtonRecord::Read(&__that, p, Tag_ButtonCharacter) )
        goto LABEL_28;
      p_Data = &v3->ButtonRecords.Data;
      while ( 1 )
      {
        v6 = 0;
        if ( v3->ButtonRecords.Data.Size )
        {
          p_Depth = &p_Data->Data->Depth;
          do
          {
            if ( *p_Depth > __that.Depth )
              break;
            ++v6;
            p_Depth += 48;
          }
          while ( v6 < v3->ButtonRecords.Data.Size );
        }
        Size = p_Data->Size;
        v9 = Size + 1;
        v25 = Size;
        if ( Size + 1 < Size )
          break;
        if ( v9 >= p_Data->Policy.Capacity )
        {
          Scaleform::ArrayDataBase<Scaleform::GFx::ButtonRecord,Scaleform::AllocatorLH<Scaleform::GFx::ButtonRecord,258>,Scaleform::ArrayDefaultPolicy>::Reserve(
            p_Data,
            p_Data,
            v9 + (v9 >> 2));
LABEL_17:
          Size = v25;
        }
        p_Data->Size = v9;
        if ( v9 > Size )
          Scaleform::ConstructorMov<Scaleform::GFx::ButtonRecord>::ConstructArray(
            (char *)&p_Data->Data[Size],
            v9 - Size);
        v13 = p_Data->Size;
        if ( v6 < v13 - 1 )
          memmove((unsigned __int8 *)&p_Data->Data[v6 + 1], (unsigned __int8 *)&p_Data->Data[v6], 96 * (v13 - v6 - 1));
        v14 = &p_Data->Data[v6];
        if ( v14 )
          Scaleform::GFx::ButtonRecord::ButtonRecord(v14, &__that);
        if ( __that.pFilters.pObject )
          Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)__that.pFilters.pObject);
        __that.ButtonMatrix.M[0][0] = 1.0;
        __that.ButtonMatrix.M[0][1] = 0.0;
        __that.ButtonMatrix.M[0][2] = 0.0;
        __that.ButtonMatrix.M[0][3] = 0.0;
        __that.ButtonMatrix.M[1][0] = 0.0;
        __that.ButtonMatrix.M[1][2] = 0.0;
        __that.ButtonMatrix.M[1][3] = 0.0;
        __that.ButtonMatrix.M[1][1] = 1.0;
        Scaleform::Render::Cxform::Cxform(&__that.ButtonCxform);
        __that.pFilters.pObject = 0;
        __that.CharacterId.Id = 0x40000;
        __that.Flags = 0;
        v3 = this;
        if ( !Scaleform::GFx::ButtonRecord::Read(&__that, p, Tag_ButtonCharacter) )
        {
          v4 = p;
LABEL_28:
          if ( __that.pFilters.pObject )
            Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)__that.pFilters.pObject);
          if ( (v4->pLoadData.pObject->FileAttributes & 8) == 0 )
          {
            pObject = v4->pLoadStates.pObject->pAS2Support.pObject;
            if ( pObject )
            {
              pObject->ReadButtonActions(pObject, v4, v3, Tag_ButtonCharacter);
              return;
            }
LABEL_33:
            Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
              &v4->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
              "GFx_ButtonLoader - AS2 support is not installed. Actions are skipped.");
            return;
          }
LABEL_57:
          Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
            &v4->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
            "GFx_ButtonLoader - AS3 Button shouldn't have AS2 actions. Skipped.");
          return;
        }
      }
      p_pFilters = (Scaleform::RefCountVImpl **)&p_Data->Data[Size - 1].pFilters;
      v26 = p_pFilters;
      pos = -1;
      do
      {
        v11 = *p_pFilters;
        if ( v11 )
          Scaleform::RefCountImpl::Release(v11);
        p_pFilters = v26 - 24;
        v12 = pos-- == 1;
        v26 -= 24;
      }
      while ( !v12 );
      if ( v9 < p_Data->Policy.Capacity >> 1 )
        Scaleform::ArrayDataBase<Scaleform::GFx::ButtonRecord,Scaleform::AllocatorLH<Scaleform::GFx::ButtonRecord,258>,Scaleform::ArrayDefaultPolicy>::Reserve(
          p_Data,
          p_Data,
          v9);
      goto LABEL_17;
    case Tag_ButtonSound:
      v16 = p->pLoadStates.pObject->pAudioState.pObject;
      if ( v16 )
      {
        v17 = (int)v16->GetSoundTagsReader(v16);
        v3->pSound = (Scaleform::GFx::ButtonSoundDef *)(*(int (__thiscall **)(int, Scaleform::GFx::LoadProcess *))(*(_DWORD *)v17 + 4))(
                                                         v17,
                                                         p);
      }
      else
      {
        Scaleform::GFx::SkipButtonSoundDef(p);
        Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogScriptWarning(
          &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
          "ButtonDef::Read - Audio library is not set. Skipping sound definitions.");
      }
      return;
    case Tag_ButtonCharacter2:
      v4 = p;
      this->Menu = Scaleform::GFx::LoadProcess::ReadU8(p) != 0;
      U16 = Scaleform::GFx::LoadProcess::ReadU16(p);
      pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
      if ( !pAltStream )
        pAltStream = &p->ProcessInfo;
      v20 = pAltStream->Stream.FilePos - pAltStream->Stream.DataSize;
      __that.ButtonMatrix.M[0][0] = 1.0;
      v21 = pAltStream->Stream.Pos + v20;
      __that.ButtonMatrix.M[0][1] = 0.0;
      __that.ButtonMatrix.M[0][2] = 0.0;
      __that.ButtonMatrix.M[0][3] = 0.0;
      __that.ButtonMatrix.M[1][0] = 0.0;
      posa = v21 + U16 - 2;
      __that.ButtonMatrix.M[1][2] = 0.0;
      __that.ButtonMatrix.M[1][3] = 0.0;
      __that.ButtonMatrix.M[1][1] = 1.0;
      Scaleform::Render::Cxform::Cxform(&__that.ButtonCxform);
      __that.pFilters.pObject = 0;
      __that.CharacterId.Id = 0x40000;
      for ( __that.Flags = 0; Scaleform::GFx::ButtonRecord::Read(&__that, p, Tag_ButtonCharacter2); __that.Flags = 0 )
      {
        v22 = 0;
        if ( v3->ButtonRecords.Data.Size )
        {
          v23 = &v3->ButtonRecords.Data.Data->Depth;
          do
          {
            if ( *v23 > __that.Depth )
              break;
            ++v22;
            v23 += 48;
          }
          while ( v22 < v3->ButtonRecords.Data.Size );
        }
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::ButtonRecord,Scaleform::AllocatorLH<Scaleform::GFx::ButtonRecord,258>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
          &v3->ButtonRecords,
          v22,
          &__that);
        if ( __that.pFilters.pObject )
          Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)__that.pFilters.pObject);
        __that.ButtonMatrix.M[0][0] = 1.0;
        __that.ButtonMatrix.M[0][1] = 0.0;
        __that.ButtonMatrix.M[0][2] = 0.0;
        __that.ButtonMatrix.M[0][3] = 0.0;
        __that.ButtonMatrix.M[1][0] = 0.0;
        __that.ButtonMatrix.M[1][2] = 0.0;
        __that.ButtonMatrix.M[1][3] = 0.0;
        __that.ButtonMatrix.M[1][1] = 1.0;
        Scaleform::Render::Cxform::Cxform(&__that.ButtonCxform);
        __that.pFilters.pObject = 0;
        __that.CharacterId.Id = 0x40000;
      }
      if ( __that.pFilters.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)__that.pFilters.pObject);
      if ( U16 > 0 )
      {
        if ( (p->pLoadData.pObject->FileAttributes & 8) != 0 )
          goto LABEL_57;
        if ( !p->pLoadStates.pObject->pAS2Support.pObject )
          goto LABEL_33;
        p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
        if ( !p_ProcessInfo )
          p_ProcessInfo = &p->ProcessInfo;
        Scaleform::GFx::Stream::SetPosition(&p_ProcessInfo->Stream, posa);
        p->pLoadStates.pObject->pAS2Support.pObject->ReadButton2ActionConditions(
          p->pLoadStates.pObject->pAS2Support.pObject,
          p,
          v3,
          Tag_ButtonCharacter2);
      }
      break;
  }
}
