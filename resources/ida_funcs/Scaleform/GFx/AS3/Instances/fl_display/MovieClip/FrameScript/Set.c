void __thiscall Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Set(
        Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript *this,
        Scaleform::MemoryHeap *pheap,
        unsigned int totalFrames,
        unsigned int cnt,
        const Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr *pdescriptors)
{
  unsigned int v5; // edi
  int v7; // ebx
  int v8; // eax
  unsigned int v9; // ecx
  unsigned int FrameCnt; // ebp
  unsigned int v11; // edi
  Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr *v12; // ebx
  Scaleform::GFx::AS3::Value *Undefined; // eax
  const Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr *v14; // eax
  unsigned int v15; // edi
  Scaleform::GFx::AS3::Value *p_Method; // ebx
  unsigned int v17; // edi
  unsigned __int8 *v18; // eax
  int v19; // kr08_4
  signed int DescrCnt; // edx
  unsigned __int8 *v21; // ecx
  signed int v22; // ebp
  int v23; // eax
  unsigned int Frame; // ebx
  unsigned int v25; // edi
  unsigned int v26; // ebx
  Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr *v27; // ecx
  signed int v28; // ecx
  int v29; // kr0C_4
  unsigned __int8 *pData; // edx
  unsigned __int16 v31; // cx
  unsigned __int8 *v32; // ecx
  int v33; // ebp
  unsigned __int8 *v34; // ecx
  unsigned int v35; // ebx
  unsigned int v36; // edi
  unsigned int v37; // ebx
  Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr *v38; // ecx
  int v39; // eax
  unsigned int actualDescrCnt; // [esp+10h] [ebp-24h]
  unsigned int actualDescrCnta; // [esp+10h] [ebp-24h]
  Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr *pdescr; // [esp+14h] [ebp-20h] BYREF
  unsigned __int8 *v43; // [esp+18h] [ebp-1Ch]
  Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr v44; // [esp+1Ch] [ebp-18h] BYREF
  int j; // [esp+38h] [ebp+4h]
  int ja; // [esp+38h] [ebp+4h]
  unsigned int newDescrCnt; // [esp+3Ch] [ebp+8h]
  unsigned int newDescrCnta; // [esp+3Ch] [ebp+8h]
  unsigned int newDescrCntb; // [esp+3Ch] [ebp+8h]
  unsigned int *cnta; // [esp+40h] [ebp+Ch]
  unsigned int cntb; // [esp+40h] [ebp+Ch]
  unsigned int cntc; // [esp+40h] [ebp+Ch]

  v5 = 0;
  actualDescrCnt = 0;
  if ( this->pData )
  {
    v7 = cnt - 1;
    actualDescrCnta = this->DescrCnt;
    v8 = cnt - 1;
    v9 = 0;
    newDescrCnt = 0;
    v43 = (unsigned __int8 *)(cnt - 1);
    j = cnt - 1;
    if ( (int)(cnt - 1) >= 0 )
    {
      cnta = &pdescriptors[v8].Frame;
      do
      {
        FrameCnt = this->FrameCnt;
        v11 = *cnta;
        if ( *cnta < FrameCnt )
        {
          if ( ((unsigned __int8)(1 << (v11 & 7)) & this->pData[v11 >> 3]) != 0 )
          {
            v12 = (Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr *)&this->pData[4 * ((int)(FrameCnt + 31) / 32)];
            pdescr = v12;
            Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
            Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr::Descr(&v44, v11, Undefined);
            v15 = Scaleform::Alg::LowerBoundSliced<Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr const *,Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr,bool (__cdecl *)(Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr const &,Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr const &)>(
                    (const Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr *const *)&pdescr,
                    0,
                    this->DescrCnt,
                    v14,
                    (bool (__cdecl *)(const Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr *, const Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr *))Scaleform::Alg::OperatorLess<Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr>::Compare);
            if ( (v44.Method.Flags & 0x1F) > 9 )
            {
              if ( (v44.Method.Flags & 0x200) != 0 )
                Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v44.Method);
              else
                Scaleform::GFx::AS3::Value::ReleaseInternal(&v44.Method);
            }
            p_Method = &v12[v15].Method;
            Scaleform::GFx::AS3::Value::Assign(p_Method, (const Scaleform::GFx::AS3::Value *)cnta - 1);
            v8 = j;
            p_Method[1].Flags = *cnta;
          }
          else
          {
            ++newDescrCnt;
          }
        }
        cnta -= 6;
        j = --v8;
      }
      while ( v8 >= 0 );
      v9 = newDescrCnt;
      v7 = (int)v43;
    }
    v17 = v9 + this->DescrCnt;
    newDescrCnta = v17;
    if ( v9 )
    {
      v18 = (unsigned __int8 *)Scaleform::Memory::pGlobalHeap->Realloc(
                                 Scaleform::Memory::pGlobalHeap,
                                 this->pData,
                                 4 * ((this->FrameCnt + 31) / 32 + 6 * v17));
      v19 = this->FrameCnt + 31;
      DescrCnt = this->DescrCnt;
      this->pData = v18;
      v21 = &v18[4 * (v19 / 32)];
      v22 = v17 - 1;
      v23 = v7;
      v43 = v21;
      ja = v7;
      if ( (int)(v17 - 1) >= DescrCnt )
      {
        pdescriptors += v7;
        cntb = (unsigned int)&v21[24 * v22];
        do
        {
          if ( v23 < 0 )
            break;
          Frame = pdescriptors->Frame;
          if ( Frame < this->FrameCnt )
          {
            v25 = pdescriptors->Frame & 7;
            v26 = Frame >> 3;
            if ( ((unsigned __int8)(1 << (pdescriptors->Frame & 7)) & this->pData[v26]) == 0 )
            {
              v27 = (Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr *)cntb;
              --v22;
              cntb -= 24;
              if ( v27 )
                Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr::Descr(v27, pdescriptors);
              this->pData[v26] |= 1 << v25;
              ++actualDescrCnta;
            }
            v17 = newDescrCnta;
          }
          v28 = this->DescrCnt;
          --pdescriptors;
          v23 = --ja;
        }
        while ( v22 >= v28 );
      }
      if ( v17 != actualDescrCnta )
        memcpy(&v43[24 * this->DescrCnt], &v43[24 * actualDescrCnta], 24 * (v17 - actualDescrCnta));
      this->DescrCnt = v17;
    }
    v5 = actualDescrCnta;
    goto LABEL_29;
  }
  v31 = cnt;
  if ( !cnt )
  {
LABEL_29:
    v29 = this->FrameCnt + 31;
    pData = this->pData;
    pdescriptors = (const Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr *)&this->pData[4 * (v29 / 32)];
    if ( this->DescrCnt != v5 )
    {
      this->DescrCnt = v5;
      this->pData = (unsigned __int8 *)Scaleform::Memory::pGlobalHeap->Realloc(
                                         Scaleform::Memory::pGlobalHeap,
                                         pData,
                                         4 * (v29 / 32 + 6 * (unsigned __int16)v5));
    }
    Scaleform::Alg::QuickSortSliced<Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr *,bool (__cdecl *)(Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr const &,Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr const &)>(
      (Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr **)&pdescriptors,
      0,
      this->DescrCnt,
      (bool (__cdecl *)(const Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr *, const Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr *))Scaleform::Alg::OperatorLess<Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr>::Compare);
    return;
  }
  if ( cnt >= totalFrames )
    v31 = totalFrames;
  this->FrameCnt = totalFrames;
  this->DescrCnt = v31;
  v32 = (unsigned __int8 *)pheap->Alloc(pheap, 4 * (((unsigned __int16)totalFrames + 31) / 32 + 6 * v31), 0);
  this->pData = v32;
  if ( v32 )
  {
    memset((int)v32, 0, (this->FrameCnt + 7) / 8);
    v33 = this->DescrCnt - 1;
    v34 = &this->pData[4 * ((this->FrameCnt + 31) / 32)];
    newDescrCntb = (unsigned int)v34;
    if ( v33 >= 0 )
    {
      pdescriptors += v33;
      cntc = (unsigned int)&v34[24 * v33];
      do
      {
        v35 = pdescriptors->Frame;
        if ( v35 < this->FrameCnt )
        {
          v36 = pdescriptors->Frame & 7;
          v37 = v35 >> 3;
          if ( ((unsigned __int8)(1 << (pdescriptors->Frame & 7)) & this->pData[v37]) == 0 )
          {
            v38 = (Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr *)cntc;
            cntc -= 24;
            if ( v38 )
              Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr::Descr(v38, pdescriptors);
            this->pData[v37] |= 1 << v36;
            ++actualDescrCnt;
          }
          v5 = actualDescrCnt;
        }
        --pdescriptors;
        --v33;
      }
      while ( v33 >= 0 );
      v34 = (unsigned __int8 *)newDescrCntb;
    }
    v39 = this->DescrCnt;
    if ( v39 != v5 )
      memcpy(v34, &v34[24 * (v39 - v5)], 24 * v5);
    goto LABEL_29;
  }
}
