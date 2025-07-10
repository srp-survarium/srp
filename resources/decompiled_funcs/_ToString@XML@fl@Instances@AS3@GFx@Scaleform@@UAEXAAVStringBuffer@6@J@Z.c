void __thiscall Scaleform::GFx::AS3::Instances::fl::XML::ToString(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::StringBuffer *buf,
        int ident)
{
  Scaleform::StringBuffer::AppendString(buf, (char *)this->Text.pNode->pData, this->Text.pNode->Size);
}
