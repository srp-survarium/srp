void __cdecl sub_481D90(void **opaque)
{
  signed int i; // esi
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v2; // ecx

  for ( i = 1; i >= 0; --i )
    sub_481C80(opaque, i);
  jpeg_free_small(opaque, opaque[1]);
  opaque[1] = 0;
  Scaleform::Render::JPEG::JPEGRwSource::TermSource(v2);
}
