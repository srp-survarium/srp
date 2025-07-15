void __thiscall Scaleform::Render::BlendModeEffect::GetRange(
        Scaleform::Render::UserDataEffect *this,
        Scaleform::Render::BundleEntryRange *result)
{
  unsigned int Length; // edx

  Length = this->Length;
  result->pFirst = &this->StartEntry;
  result->pLast = &this->EndEntry;
  result->Length = Length;
}
