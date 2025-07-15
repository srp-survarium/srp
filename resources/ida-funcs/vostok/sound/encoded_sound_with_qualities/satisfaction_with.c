double __thiscall vostok::sound::encoded_sound_with_qualities::satisfaction_with(
        vostok::sound::encoded_sound_with_qualities *this,
        unsigned int quality_level,
        const vostok::resources::positional_unmanaged_resource *resource_user,
        unsigned int positional_users_count)
{
  return (double)(2 - quality_level) * 0.5;
}
