/*
 * ROX-Filer, filer for the ROX desktop project
 * By Thomas Leonard, <tal197@users.sourceforge.net>.
 */

#ifndef _DISPLAY_H
#define _DISPLAY_H

#define ROW_HEIGHT_LARGE 64

#include <gtk/gtk.h>
#include <sys/types.h>
#include <dirent.h>

typedef struct _ViewData ViewData;

struct _ViewData
{
	PangoLayout *details;

	int	name_width;
	int	name_height;
	int	details_width;
	int	details_height;

	MaskedPixmap *image;		/* Image; not thumbnail */
	GdkPixbuf *thumb;
	gboolean may_thumb;
	int base_type; /* for time lag */
	gboolean recent;
};

extern Option o_display_dirs_first;
extern Option o_display_inherit_options, o_display_sort_by;
extern Option o_display_size, o_display_details, o_display_show_hidden;
extern Option o_display_show_headers, o_display_show_full_type;
extern Option o_display_show_thumbs;
extern Option o_display_show_dir_thumbs;
extern Option o_large_width;
extern Option o_small_width;
extern Option o_max_length;
extern Option o_vertical_order_small, o_vertical_order_large;
extern Option o_xattr_show;
extern Option o_view_alpha;
extern Option o_use_background_colour;
extern Option o_background_colour;
extern int huge_size;

/* Prototypes */
void display_init(void);
void display_set_layout(FilerWindow  *filer_window,
			DisplayStyle style,
			DetailsType  details,
			gboolean     force_resize);
void display_set_hidden(FilerWindow *filer_window, gboolean hidden);
void display_set_filter_directories(FilerWindow *filer_window, gboolean filter_directories);
void display_update_hidden(FilerWindow *filer_window);
void display_set_filter(FilerWindow *filer_window, FilterType type,
			const gchar *filter_string);
void display_set_thumbs(FilerWindow *filer_window, gboolean thumbs);
int sort_by_name(const void *item1, const void *item2);
int sort_by_type(const void *item1, const void *item2);
int sort_by_datea(const void *item1, const void *item2);
int sort_by_datec(const void *item1, const void *item2);
int sort_by_datem(const void *item1, const void *item2);
int sort_by_size(const void *item1, const void *item2);
int sort_by_owner(const void *item1, const void *item2);
int sort_by_group(const void *item1, const void *item2);
void display_set_sort_type(FilerWindow *filer_window, SortType sort_type,
			   GtkSortType order);
void display_set_autoselect(FilerWindow *filer_window, const gchar *leaf);

void draw_large_icon(GdkWindow *window,
		     GtkStyle *style,
		     GdkRectangle *area,
		     DirItem  *item,
		     GdkPixbuf *image,
		     gboolean selected,
		     GdkColor *color);
gboolean display_is_truncated(FilerWindow *filer_window, int i);
void display_change_size(FilerWindow *filer_window, gboolean bigger);

ViewData *display_create_viewdata(FilerWindow *filer_window, DirItem *item);
void display_update_view(FilerWindow *filer_window,
			 DirItem *item,
			 ViewData *view,
			 gboolean update_name_layout);
PangoLayout *make_layout(FilerWindow *fw, DirItem *item);
void display_update_views(FilerWindow *filer_window);
void draw_small_icon(GdkWindow *window,
					GtkStyle *style,
					GdkRectangle *area,
					DirItem  *item,
					GdkPixbuf *image,
					gboolean selected,
					GdkColor *color);
void draw_huge_icon(
					GdkWindow *window,
					GtkStyle *style,
					GdkRectangle *area,
					DirItem *item,
					GdkPixbuf *image,
					gboolean selected,
					GdkColor *color);
void display_set_actual_size(FilerWindow *filer_window, gboolean force_resize);
void draw_emblem_on_icon(GdkWindow *window, GtkStyle   *style,
				const char *stock_id,
			 int *x, int y, GdkColor *color);

#endif /* _DISPLAY_H */
