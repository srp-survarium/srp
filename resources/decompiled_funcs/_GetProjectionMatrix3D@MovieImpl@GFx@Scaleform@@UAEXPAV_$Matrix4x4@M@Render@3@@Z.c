void __thiscall Scaleform::GFx::MovieImpl::GetProjectionMatrix3D(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::Render::Matrix4x4<float> *projMat)
{
  Scaleform::GFx::DisplayObjContainer *v2; // eax

  v2 = this->pASMovieRoot.pObject->GetRootMovie(this->pASMovieRoot.pObject, 0);
  if ( v2 )
    v2->GetProjectionMatrix3D(v2, projMat, 0);
}
