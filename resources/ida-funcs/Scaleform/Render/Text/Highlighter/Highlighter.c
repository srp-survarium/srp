void __thiscall Scaleform::Render::Text::Highlighter::Highlighter(Scaleform::Render::Text::Highlighter *this)
{
  this->Highlighters.Data.Data = 0;
  this->Highlighters.Data.Size = 0;
  this->Highlighters.Data.Policy.Capacity = 0;
  this->LastId = 0;
  this->CorrectionPos = 0;
  this->CorrectionLen = 0;
  this->Valid = 0;
  this->HasUnderline = 0;
}
