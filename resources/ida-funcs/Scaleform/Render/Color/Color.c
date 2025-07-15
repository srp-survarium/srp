void __thiscall Scaleform::Render::Color::Color(
        vostok::vectora_allocator<void const *> *this,
        const vostok::vectora_allocator<vostok::collision::object const *> *allocator)
{
  this->m_allocator = allocator->m_allocator;
}
