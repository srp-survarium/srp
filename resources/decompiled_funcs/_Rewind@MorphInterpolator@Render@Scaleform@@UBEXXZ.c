void __thiscall Scaleform::Render::MorphInterpolator::Rewind(Scaleform::Render::MorphInterpolator *this)
{
  qmemcpy(&this->Pos2, &this->Pos2s, sizeof(this->Pos2));
}
