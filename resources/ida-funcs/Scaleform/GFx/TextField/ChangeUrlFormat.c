void __thiscall Scaleform::GFx::TextField::ChangeUrlFormat(
        Scaleform::GFx::TextField *this,
        Scaleform::GFx::TextField::LinkEvent event,
        const Scaleform::Render::Text::Style *mouseIndex,
        const Scaleform::Range *purlRange)
{
  unsigned __int8 AvmObjOffset; // al
  int v6; // eax
  const char *v7; // ebp
  Scaleform::GFx::TextField::CSSHolderBase *pObject; // eax
  Scaleform::GFx::TextField::CSSHolderBase *v10; // eax
  unsigned int UrlZoneIndex; // ebx
  Scaleform::RangeData<Scaleform::GFx::TextField::CSSHolderBase::UrlZone> *Data; // eax
  Scaleform::RangeData<Scaleform::GFx::TextField::CSSHolderBase::UrlZone> *v13; // edi
  Scaleform::Range *i; // edi
  Scaleform::GFx::TextField::CSSHolderBase *v15; // eax
  Scaleform::RangeData<Scaleform::GFx::TextField::CSSHolderBase::UrlZone> *v16; // ecx
  unsigned int HitCount; // eax
  Scaleform::GFx::TextField::CSSHolderBase *v18; // ecx
  Scaleform::GFx::TextField::CSSHolderBase *v19; // edx
  int v20; // ecx
  Scaleform::GFx::TextField::CSSHolderBase *v21; // eax
  Scaleform::GFx::TextField::CSSHolderBase *v23; // eax
  Scaleform::RangeData<Scaleform::GFx::TextField::CSSHolderBase::UrlZone> *v24; // edx
  unsigned __int8 v25; // al
  int v26; // eax
  Scaleform::Range *j; // edi
  Scaleform::GFx::TextField::CSSHolderBase *v28; // eax
  Scaleform::RangeData<Scaleform::GFx::TextField::CSSHolderBase::UrlZone> *v29; // edx
  unsigned __int8 v30; // al
  int v31; // eax
  unsigned int OverCount; // eax
  Scaleform::GFx::TextField::CSSHolderBase *v33; // eax
  Scaleform::GFx::TextField::CSSHolderBase *v34; // eax
  unsigned __int8 v35; // al
  int v36; // eax
  unsigned int Index; // ebx
  unsigned int v38; // eax
  unsigned int v39; // eax
  const Scaleform::Render::Text::StyleManagerBase *v40; // eax
  const Scaleform::Render::Text::StyleManagerBase *v41; // eax
  const Scaleform::Render::Text::TextFormat *v42; // ebx
  const Scaleform::Render::Text::StyleManagerBase *v43; // eax
  const Scaleform::Render::Text::TextFormat *v44; // ebp
  Scaleform::MemoryHeap *v45; // eax
  const Scaleform::Render::Text::TextFormat *v46; // eax
  const Scaleform::Render::Text::TextFormat *v47; // eax
  const Scaleform::Render::Text::TextFormat *v48; // eax
  Scaleform::Render::Text::TextFormat fmt; // [esp+34h] [ebp-50h] BYREF
  Scaleform::Render::Text::TextFormat result; // [esp+5Ch] [ebp-28h] BYREF
  const Scaleform::Render::Text::Style *pstyle; // [esp+8Ch] [ebp+8h]
  const Scaleform::Render::Text::Style *pstylea; // [esp+8Ch] [ebp+8h]
  const Scaleform::Render::Text::Style *pstyleb; // [esp+8Ch] [ebp+8h]

  AvmObjOffset = this->AvmObjOffset;
  if ( AvmObjOffset )
  {
    v6 = (*(int (__thiscall **)(char *))(*((_DWORD *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                         + AvmObjOffset)
                                       + 16))(
           (char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
         + 4 * AvmObjOffset);
    if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v6 + 96))(v6) )
    {
      v7 = 0;
      switch ( event )
      {
        case Link_press:
          pObject = this->pCSSData.pObject;
          if ( pObject->MouseState[(_DWORD)mouseIndex].UrlZoneIndex )
          {
            if ( pObject->MouseState[(_DWORD)mouseIndex].HitBit )
              return;
            pObject->MouseState[(_DWORD)mouseIndex].HitBit = 1;
            v10 = this->pCSSData.pObject;
            UrlZoneIndex = v10->MouseState[(_DWORD)mouseIndex].UrlZoneIndex;
            Data = v10->UrlZones.Ranges.Data.Data;
            v13 = &Data[UrlZoneIndex - 1];
            if ( Data[UrlZoneIndex - 1].Data.HitCount )
            {
              ++v13->Data.HitCount;
              return;
            }
          }
          else
          {
            pstyle = (const Scaleform::Render::Text::Style *)pObject->UrlZones.Ranges.Data.Size;
            if ( !pstyle )
              return;
            for ( i = pObject->UrlZones.Ranges.Data.Data;
                  !Scaleform::Range::Intersects(i, purlRange);
                  i = (Scaleform::Range *)((char *)i + 20) )
            {
              if ( ++v7 >= (const char *)pstyle )
                return;
            }
            v15 = this->pCSSData.pObject;
            v16 = v15->UrlZones.Ranges.Data.Data;
            v15->MouseState[(_DWORD)mouseIndex].UrlZoneIndex = (unsigned int)(v7 + 1);
            v13 = &v16[(_DWORD)v7];
            this->pCSSData.pObject->MouseState[(_DWORD)mouseIndex].HitBit = 1;
          }
          if ( v13 )
          {
            HitCount = v13->Data.HitCount;
            v13->Data.HitCount = HitCount + 1;
            if ( !HitCount )
              goto LABEL_50;
          }
          return;
        case Link_release:
          v18 = this->pCSSData.pObject;
          if ( v18->MouseState[(_DWORD)mouseIndex].UrlZoneIndex && v18->MouseState[(_DWORD)mouseIndex].HitBit )
          {
            v18->MouseState[(_DWORD)mouseIndex].HitBit = 0;
            v19 = this->pCSSData.pObject;
            v20 = v19->MouseState[(_DWORD)mouseIndex].UrlZoneIndex - 1;
            if ( !v19->MouseState[(_DWORD)mouseIndex].OverBit )
              v19->MouseState[(_DWORD)mouseIndex].UrlZoneIndex = 0;
            v13 = &this->pCSSData.pObject->UrlZones.Ranges.Data.Data[v20];
            if ( !v13->Data.HitCount )
              goto LABEL_51;
            if ( !--v13->Data.HitCount )
            {
              if ( v13->Data.OverCount )
                v7 = "a:hover";
              goto LABEL_51;
            }
          }
          return;
        case Link_rollover:
          v21 = this->pCSSData.pObject;
          if ( v21->MouseState[(_DWORD)mouseIndex].UrlZoneIndex )
          {
            if ( v21->MouseState[(_DWORD)mouseIndex].OverBit )
              return;
            v21->MouseState[(_DWORD)mouseIndex].OverBit = 1;
            v23 = this->pCSSData.pObject;
            v24 = v23->UrlZones.Ranges.Data.Data;
            v13 = &v24[v23->MouseState[(_DWORD)mouseIndex].UrlZoneIndex - 1];
            if ( v24[v23->MouseState[(_DWORD)mouseIndex].UrlZoneIndex - 1].Data.OverCount )
            {
              ++v13->Data.OverCount;
              v25 = this->AvmObjOffset;
              if ( v25 )
              {
                v26 = (*(int (__thiscall **)(char *))(*((_DWORD *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                      + v25)
                                                    + 16))(
                        (char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                      + 4 * v25);
                (*(void (__thiscall **)(int, int, int, const Scaleform::Render::Text::Style *))(*(_DWORD *)v26 + 104))(
                  v26,
                  2,
                  v13->Index,
                  mouseIndex);
              }
              return;
            }
          }
          else
          {
            pstylea = (const Scaleform::Render::Text::Style *)v21->UrlZones.Ranges.Data.Size;
            if ( !pstylea )
              return;
            for ( j = v21->UrlZones.Ranges.Data.Data;
                  !Scaleform::Range::Intersects(j, purlRange);
                  j = (Scaleform::Range *)((char *)j + 20) )
            {
              if ( ++v7 >= (const char *)pstylea )
                return;
            }
            v28 = this->pCSSData.pObject;
            v29 = v28->UrlZones.Ranges.Data.Data;
            v28->MouseState[(_DWORD)mouseIndex].UrlZoneIndex = (unsigned int)(v7 + 1);
            this->pCSSData.pObject->MouseState[(_DWORD)mouseIndex].OverBit = 1;
            v30 = this->AvmObjOffset;
            v13 = &v29[(_DWORD)v7];
            if ( v30 )
            {
              v31 = (*(int (__thiscall **)(char *))(*((_DWORD *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                    + v30)
                                                  + 16))(
                      (char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                    + 4 * v30);
              (*(void (__thiscall **)(int, int, int, const Scaleform::Render::Text::Style *))(*(_DWORD *)v31 + 104))(
                v31,
                2,
                v13->Index,
                mouseIndex);
            }
          }
          if ( v13 )
          {
            if ( !v13->Data.HitCount )
            {
              OverCount = v13->Data.OverCount;
              v13->Data.OverCount = OverCount + 1;
              if ( !OverCount )
              {
                v7 = "a:hover";
                goto LABEL_51;
              }
            }
          }
          break;
        case Link_rollout:
          v33 = this->pCSSData.pObject;
          if ( !v33->MouseState[(_DWORD)mouseIndex].UrlZoneIndex || !v33->MouseState[(_DWORD)mouseIndex].OverBit )
            return;
          v33->MouseState[(_DWORD)mouseIndex].OverBit = 0;
          v34 = this->pCSSData.pObject;
          v13 = &v34->UrlZones.Ranges.Data.Data[v34->MouseState[(_DWORD)mouseIndex].UrlZoneIndex - 1];
          if ( !v34->MouseState[(_DWORD)mouseIndex].HitBit )
            v34->MouseState[(_DWORD)mouseIndex].UrlZoneIndex = 0;
          if ( !v13->Data.OverCount )
            goto LABEL_51;
          --v13->Data.OverCount;
          v35 = this->AvmObjOffset;
          if ( v35 )
          {
            v36 = (*(int (__thiscall **)(char *))(*((_DWORD *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                  + v35)
                                                + 16))(
                    (char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                  + 4 * v35);
            (*(void (__thiscall **)(int, int, int, const Scaleform::Render::Text::Style *))(*(_DWORD *)v36 + 104))(
              v36,
              3,
              v13->Index,
              mouseIndex);
          }
          if ( !v13->Data.OverCount )
          {
            if ( v13->Data.HitCount )
LABEL_50:
              v7 = "a:active";
LABEL_51:
            if ( v13->Data.SavedFmt.pObject )
            {
              Index = v13->Index;
              v38 = v13->Index + v13->Length;
              if ( v38 < v13->Index )
                v39 = 0;
              else
                v39 = v38 - Index;
              Scaleform::Render::Text::StyledText::Remove(
                this->pDocument.pObject->pDocument.pObject,
                (Scaleform::Render::Text::Paragraph *)v13,
                Index,
                v39);
              Scaleform::Render::Text::StyledText::InsertStyledText(
                this->pDocument.pObject->pDocument.pObject,
                v13->Data.SavedFmt.pObject,
                Index,
                0xFFFFFFFF);
            }
            if ( v7 )
            {
              v40 = this->pCSSData.pObject->GetTextStyleManager(this->pCSSData.pObject);
              pstyleb = v40->GetStyle(v40, CSS_Tag, v7, -1u);
              if ( pstyleb )
              {
                v41 = this->pCSSData.pObject->GetTextStyleManager(this->pCSSData.pObject);
                v42 = (const Scaleform::Render::Text::TextFormat *)v41->GetStyle(v41, CSS_Tag, "a", -1u);
                v43 = this->pCSSData.pObject->GetTextStyleManager(this->pCSSData.pObject);
                v44 = (const Scaleform::Render::Text::TextFormat *)v43->GetStyle(v43, CSS_Tag, "a:link", -1u);
                v45 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
                Scaleform::Render::Text::TextFormat::TextFormat(&fmt, v45);
                if ( v42 )
                {
                  v46 = Scaleform::Render::Text::TextFormat::Merge(&fmt, &result, v42);
                  Scaleform::Render::Text::TextFormat::operator=(&fmt, v46);
                  Scaleform::Render::Text::TextFormat::~TextFormat(&result);
                }
                if ( v44 )
                {
                  v47 = Scaleform::Render::Text::TextFormat::Merge(&fmt, &result, v44);
                  Scaleform::Render::Text::TextFormat::operator=(&fmt, v47);
                  Scaleform::Render::Text::TextFormat::~TextFormat(&result);
                }
                v48 = Scaleform::Render::Text::TextFormat::Merge(&fmt, &result, &pstyleb->mTextFormat);
                Scaleform::Render::Text::TextFormat::operator=(&fmt, v48);
                Scaleform::Render::Text::TextFormat::~TextFormat(&result);
                Scaleform::Render::Text::DocView::SetTextFormat(
                  this->pDocument.pObject,
                  &fmt,
                  v13->Index,
                  v13->Index + v13->Length);
                Scaleform::Render::Text::TextFormat::~TextFormat(&fmt);
              }
            }
          }
          return;
        default:
          return;
      }
    }
  }
}
