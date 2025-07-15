void __thiscall Scaleform::GFx::AS3::Instances::fl::XML::ToString(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::StringBuffer *buf,
        int ident)
{
  Scaleform::StringBuffer::AppendString(buf, (const __m128i *)this->Text.pNode->pData, this->Text.pNode->Size);
}
