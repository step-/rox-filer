/* vi: set cindent:
 * $Id$
 *
 * ROX-Filer, filer for the ROX desktop project
 * By Thomas Leonard, <tal197@ecs.soton.ac.uk>.
 */

#ifndef _MOUNT_H
#define _MOUNT_H

extern GHashTable *mount_points;

typedef struct _MountPoint MountPoint;

struct _MountPoint
{
	char	*name;		/* eg: /dev/hda4 */
	char	*dir;		/* eg: /home */
};

/* Prototypes */
void mount_init();

#endif /* _MOUNT_H */
