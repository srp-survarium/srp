void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot::getTextRunInfo(
        Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *result,
        unsigned int beginIndex,
        unsigned int endIndex)
{
  Scaleform::GFx::AS3::VM *pVM; // edi
  Scaleform::GFx::AS3::Instances::fl::Array *pV; // ebx
  unsigned int RefCount; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> v8; // [esp+F0h] [ebp-74h] BYREF
  Scaleform::GFx::StaticTextSnapshotData::GlyphVisitor pvisitor; // [esp+F4h] [ebp-70h] BYREF
  Scaleform::GFx::AS3::VM *v10; // [esp+154h] [ebp-10h]
  Scaleform::GFx::AS3::Instances::fl::Array *v11; // [esp+158h] [ebp-Ch]

  pVM = this->pTraits.pObject->pVM;
  pV = Scaleform::GFx::AS3::VM::MakeArray(pVM, &v8)->pV;
  pvisitor.Matrix.M[0][0] = 1.0;
  pvisitor.Matrix.M[0][1] = 0.0;
  pvisitor.Matrix.M[0][2] = 0.0;
  pvisitor.Matrix.M[0][3] = 0.0;
  pvisitor.Matrix.M[1][0] = 0.0;
  pvisitor.Matrix.M[1][2] = 0.0;
  pvisitor.Matrix.M[1][3] = 0.0;
  pvisitor.Corners.x1 = 0.0;
  v8.pV = pV;
  pvisitor.Corners.y1 = 0.0;
  pvisitor.__vftable = (Scaleform::GFx::StaticTextSnapshotData::GlyphVisitor_vtbl *)&Scaleform::GFx::AS3::TextSnapshotGlyphVisitor::`vftable';
  pvisitor.Corners.x2 = 0.0;
  v10 = pVM;
  pvisitor.Corners.y2 = 0.0;
  v11 = pV;
  pvisitor.Matrix.M[1][1] = 1.0;
  Scaleform::GFx::StaticTextSnapshotData::Visit(&this->SnapshotData, &pvisitor, beginIndex, endIndex);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)result,
    (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&v8);
  pvisitor.__vftable = (Scaleform::GFx::StaticTextSnapshotData::GlyphVisitor_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
  if ( pV && ((unsigned __int8)pV & 1) == 0 )
  {
    RefCount = pV->RefCount;
    if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
    {
      pV->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pV);
    }
  }
}
