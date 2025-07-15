void __stdcall Scaleform::GFx::GFx_DefineSubImageLoader(
        Scaleform::GFx::LoadProcess *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  int v4; // eax
  unsigned int Pos; // eax
  unsigned __int16 v6; // cx
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // esi
  int v8; // eax
  unsigned int v9; // eax
  int v10; // ecx
  Scaleform::GFx::SWFProcessInfo *v11; // esi
  int v12; // ebx
  int v13; // edx
  unsigned int v14; // eax
  unsigned __int8 *pBuffer; // ecx
  __int16 v16; // dx
  Scaleform::GFx::SWFProcessInfo *v17; // esi
  int v18; // eax
  unsigned int v19; // eax
  unsigned __int8 *v20; // ecx
  __int16 v21; // dx
  Scaleform::GFx::SWFProcessInfo *v22; // esi
  int v23; // eax
  unsigned int v24; // eax
  unsigned __int8 *v25; // ecx
  __int16 v26; // dx
  Scaleform::GFx::SWFProcessInfo *v27; // esi
  int v28; // eax
  unsigned int v29; // eax
  unsigned __int8 *v30; // ecx
  __int16 v31; // dx
  unsigned __int16 v32; // bp
  Scaleform::GFx::SubImageResourceInfo *v33; // esi
  Scaleform::GFx::SubImageResourceInfo *v34; // eax
  unsigned __int16 v35; // [esp+10h] [ebp-18h]
  unsigned __int16 v36; // [esp+14h] [ebp-14h]
  Scaleform::GFx::ResourceHandle v37; // [esp+18h] [ebp-10h] BYREF
  Scaleform::GFx::ResourceData result; // [esp+20h] [ebp-8h] BYREF
  unsigned __int16 v39; // [esp+2Ch] [ebp+4h]

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  v4 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
  pAltStream->Stream.UnusedBits = 0;
  if ( v4 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  Pos = pAltStream->Stream.Pos;
  v6 = *(_WORD *)&pAltStream->Stream.pBuffer[Pos];
  pAltStream->Stream.Pos = Pos + 2;
  p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  v37.HType = v6;
  if ( !p_ProcessInfo )
    p_ProcessInfo = &p->ProcessInfo;
  v8 = p_ProcessInfo->Stream.DataSize - p_ProcessInfo->Stream.Pos;
  p_ProcessInfo->Stream.UnusedBits = 0;
  if ( v8 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&p_ProcessInfo->Stream, 2);
  v9 = p_ProcessInfo->Stream.Pos;
  v10 = *(unsigned __int16 *)&p_ProcessInfo->Stream.pBuffer[v9];
  p_ProcessInfo->Stream.Pos = v9 + 2;
  v11 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  v12 = v10;
  if ( !v11 )
    v11 = &p->ProcessInfo;
  v13 = v11->Stream.DataSize - v11->Stream.Pos;
  v11->Stream.UnusedBits = 0;
  if ( v13 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&v11->Stream, 2);
  v14 = v11->Stream.Pos;
  pBuffer = v11->Stream.pBuffer;
  v16 = pBuffer[v14 + 1];
  LOWORD(pBuffer) = pBuffer[v14];
  v11->Stream.Pos = v14 + 2;
  v17 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  v39 = (unsigned __int16)pBuffer | (v16 << 8);
  if ( !v17 )
    v17 = &p->ProcessInfo;
  v18 = v17->Stream.DataSize - v17->Stream.Pos;
  v17->Stream.UnusedBits = 0;
  if ( v18 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&v17->Stream, 2);
  v19 = v17->Stream.Pos;
  v20 = v17->Stream.pBuffer;
  v21 = v20[v19 + 1];
  LOWORD(v20) = v20[v19];
  v17->Stream.Pos = v19 + 2;
  v22 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  v35 = (unsigned __int16)v20 | (v21 << 8);
  if ( !v22 )
    v22 = &p->ProcessInfo;
  v23 = v22->Stream.DataSize - v22->Stream.Pos;
  v22->Stream.UnusedBits = 0;
  if ( v23 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&v22->Stream, 2);
  v24 = v22->Stream.Pos;
  v25 = v22->Stream.pBuffer;
  v26 = v25[v24 + 1];
  LOWORD(v25) = v25[v24];
  v22->Stream.Pos = v24 + 2;
  v27 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  v36 = (unsigned __int16)v25 | (v26 << 8);
  if ( !v27 )
    v27 = &p->ProcessInfo;
  v28 = v27->Stream.DataSize - v27->Stream.Pos;
  v27->Stream.UnusedBits = 0;
  if ( v28 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&v27->Stream, 2);
  v29 = v27->Stream.Pos;
  v30 = v27->Stream.pBuffer;
  v31 = v30[v29 + 1];
  LOWORD(v30) = v30[v29];
  v27->Stream.Pos = v29 + 2;
  v32 = (unsigned __int16)v30 | (v31 << 8);
  v33 = 0;
  v34 = (Scaleform::GFx::SubImageResourceInfo *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                  Scaleform::Memory::pGlobalHeap,
                                                  32,
                                                  0);
  if ( v34 )
  {
    v34->RefCount = 1;
    v34->__vftable = (Scaleform::GFx::SubImageResourceInfo_vtbl *)&Scaleform::GFx::SubImageResourceInfo::`vftable';
    v34->ImageId.Id = 0x40000;
    v34->Image.pObject = 0;
    v34->Rect.x1 = 0;
    v34->Rect.y1 = 0;
    v34->Rect.x2 = 0;
    v34->Rect.y2 = 0;
    v33 = v34;
  }
  v33->ImageId.Id = v12 | 0x90000;
  v33->Rect.y1 = v35;
  v33->Rect.x1 = v39;
  v33->Rect.x2 = v36;
  v33->Rect.y2 = v32;
  Scaleform::GFx::SubImageResourceCreator::CreateSubImageResourceData(&result, v33);
  Scaleform::GFx::LoadProcess::AddDataResource(p, &v37, (Scaleform::GFx::ResourceId)v37.HType, &result);
  if ( v37.HType == RH_Pointer && v37.BindIndex )
    Scaleform::GFx::Resource::Release(v37.pResource);
  if ( result.pInterface )
    result.pInterface->Release(result.pInterface, result.hData);
  if ( v33 )
    Scaleform::RefCountNTSImpl::Release(v33);
}
