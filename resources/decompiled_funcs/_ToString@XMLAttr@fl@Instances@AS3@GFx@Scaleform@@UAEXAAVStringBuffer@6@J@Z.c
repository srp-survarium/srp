void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLAttr::ToString(
        Scaleform::GFx::AS3::Instances::fl::XMLAttr *this,
        Scaleform::StringBuffer *buf,
        int __formal)
{
  Scaleform::StringBuffer::AppendString(buf, (char *)this->Data.pNode->pData, this->Data.pNode->Size);
}
