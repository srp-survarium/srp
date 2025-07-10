void __thiscall Scaleform::GFx::AS3::Classes::fl_text::Font::enumerateFonts_::_2_::FontsVisitor::Visit(
        Scaleform::GFx::AS3::Classes::fl_text::Font::enumerateFonts::__l2::FontsVisitor *this,
        Scaleform::GFx::MovieDef *__formal,
        Scaleform::GFx::Resource *presource,
        Scaleform::GFx::ResourceId a4,
        const char *a5)
{
  Scaleform::GFx::Resource *v5; // esi
  Scaleform::HashSet<Scaleform::Ptr<Scaleform::Render::Font>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> >,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> >,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Font>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::Font>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> > > > *Fonts; // [esp-8h] [ebp-10h]

  v5 = presource;
  if ( (presource->GetResourceTypeCode(presource) & 0xFF00) == 0x200 )
  {
    Fonts = this->Fonts;
    presource = (Scaleform::GFx::Resource *)v5[1].__vftable;
    Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::Font>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font>>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font>>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Font>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::Font>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font>>>>::Set<Scaleform::Render::Font *>(
      Fonts,
      Fonts,
      &presource);
  }
}
