void __thiscall Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo::FontSearchPathInfo(
        Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *this,
        int indent)
{
  this->Indent = indent;
  Scaleform::StringBuffer::StringBuffer(&this->Info, Scaleform::Memory::pGlobalHeap);
}
