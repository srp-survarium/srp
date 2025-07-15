unsigned int __thiscall Scaleform::GFx::ResourceFileInfo::GetHashCode(Scaleform::GFx::ResourceFileInfo *this)
{
  return Scaleform::String::BernsteinHashFunction(
           (char *)((this->FileName.HeapTypeBits & 0xFFFFFFFC) + 8),
           *(_DWORD *)(this->FileName.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF,
           0x1505u)
       ^ this->Format;
}
