void __thiscall vostok::sound::receiver_collision::~receiver_collision(vostok::sound::receiver_collision *this)
{
  vostok::collision::delete_object(
    (vostok::memory::base_allocator *)vostok::sound::g_allocator.m_object,
    this->m_collision);
  this->m_collision = 0;
}
