void __thiscall Scaleform::GFx::AS3::IMEManager::SetIMEMoviePath(
        Scaleform::GFx::AS3::IMEManager *this,
        char *pcandidateSwfPath)
{
  Scaleform::String::operator=(&this->CandidateSwfPath, pcandidateSwfPath);
}
