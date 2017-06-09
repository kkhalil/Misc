/*
 * Title:	assign5.c
 * Author:	Dilrpeet Chana
 * Description:	Student organization system
 *		using Linked lists
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct courseInfo {
	int id;
	char name[30];
};
typedef struct courseInfo CourseInfo;

struct studentInfo {
	char id[10];
	char first_name[21];
	char last_name[26];
	int num_courses;
	CourseInfo c_info[10];
	struct studentInfo *next;
};
typedef struct studentInfo StudentInfo;

int length(StudentInfo *head);						 // Get length of Linked List
void addStudent(StudentInfo *head);					 // Add new students
void addStudentInfo(StudentInfo *head, StudentInfo *n_student);		 // Add new student
void deleteStudent(StudentInfo *head, char *id);			 // Remove student
StudentInfo *searchStudent(StudentInfo *head, char *index, bool is_id);  // Find student
void displayInfoAll(StudentInfo *head);					 // Show info of all students
void displayInfo(StudentInfo info);					 // Show info ofspecified student
void save(StudentInfo *head);						 // Save students to a file
void load(StudentInfo *head);						 // Load students from a file

int main() {
	StudentInfo *head = malloc(sizeof(StudentInfo));
	strcpy(head->id, "000000000");
	head->next = NULL;

	//load(head);

	while (true) {
		printf("1. Add Student\n");
		printf("2. Delete Student\n");
		printf("3. Search Student\n");
		printf("4. Show Me The People\n");
		printf("5. Save\n");
		printf("0. Exit\n");

		printf("Length: %d\n", length(head));

		int user_in;
		scanf("%d", &user_in);

		if (user_in == 0) {
			save(head);
			free(head);
			return 0;
		}
		else if (user_in == 1) {
			addStudent(head);
		}
		else if (user_in == 2) {
			char target[10];
			scanf("%s", target);
			deleteStudent(head, target);
		}
		else if (user_in == 3) {
			char target;
			printf("By id[y/n]: ");
			scanf("%c", &target);
			if (target == 'y') {
				char id[10];
				printf("Enter id: ");
				scanf("%s", id);
				searchStudent(head, id, true);
			}
			else if (target == 'n') {
				char name[26];
				printf("Enter last name: ");
				scanf("%s", name);
				searchStudent(head, name, false);
			}
			else {
				printf("Invalid input\n");
			}
		}
		else if (user_in == 4) {
			displayInfoAll(head);
		}
		else if (user_in == 5) {
			save(head);
		}
		else {
			printf("Invalid input\n");
		}
	}

	return 0;
}

/*
 * Description:	Get length of Linked List
 * Parameters:	Pointer to head of LList
 * Returns:	length of array
**/
int length(StudentInfo *head) {
	int len = 0;
	for (StudentInfo *s = head; s->next != NULL; s = s->next, len++);

	return len;
}

/*
 * Description:	Add student from user input
 * Parameters:	Pointer to head of LList
 * Returns:	void
**/
void addStudent(StudentInfo *head) {
	StudentInfo *n_student = malloc(sizeof(StudentInfo));

	printf("Enter the student's info (id first_name last_name number_of_courses): ");
	scanf("%s %s %s %d", n_student->id, n_student->first_name, n_student->last_name, &(n_student->num_courses));

	for (int i = 0; i < n_student->num_courses; i++) {
		printf("Enter course #%d (name id): ", i + 1);
		scanf("%s %d", n_student->c_info[i].name, &(n_student->c_info[i].id));
	}

	addStudentInfo(head, n_student);
}

/*
 * Description:	Add a student
 * Parameters:	Pointer to head of LList
 *		Pointer to new Student
 * Returns:	void
**/
void addStudentInfo(StudentInfo *head, StudentInfo *n_student) {
	StudentInfo *s = head;
	printf("1");
        while (true) {
		printf("2");
                if (s->next == NULL) {
			printf("3");
                        break;
                }
		// Break end if trying to add head
		else if (strcmp(s->id, "000000000")) {
			printf("4");
			return;
		}
                else if (strcmp(s->id, n_student->id) < 0 && strcmp(s->next->id, n_student->id) > 0) {
			printf("5");
                        break;
                }
                else {
			printf("6");
                        s = s->next;
                }

		printf("7");
        }
	printf("8");
        n_student->next = s->next;
        s->next = n_student;
	printf("9");
}

/*
 * Description:	Delete student with specified id
 * Parameters:	Pointer to head of LList
 *		Pointer to id of student
 * Returns:	void
**/
void deleteStudent(StudentInfo *head, char *id) {
	StudentInfo *s;
	for (s = head; s->next != NULL && strcmp(s->next->id, id) != 0; s = s->next);

	s->next = s->next->next;
}

/*
 * Description:	Search for specified student
 * Parameters:	Pointer to head of LList
 *		Pointer to index to search by
 *		Boolean is_id: true if index represents id
 * Returns:	StudentInfo of found student or NULL
**/
StudentInfo *searchStudent(StudentInfo *head, char *index, bool is_id) {
	StudentInfo *stu = NULL;
	StudentInfo *ret = NULL;

	// Search by id
	if (is_id) {
		for (stu = head; stu->next != NULL && strcmp(stu->id, index); stu = stu->next);
	}
	else {
		for (stu = head; stu->next != NULL && strcmp(stu->last_name, index); stu = stu->next);
	}

	displayInfo(*stu);
	return stu;
}

/*
 * Description:	Display info of all students
 * Parameters:	Pointer to head of LList
 * Returns:	void
**/
void displayInfoAll(StudentInfo *head) {
	for (StudentInfo *s = head->next; s->next != NULL; s = s->next) {
		displayInfo(*s);
	}
}

/*
 * Description: Display info of specified info
 * Parameters:	info of Student
 * Returns:	void
**/
void displayInfo(StudentInfo info) {
	printf("%s\n", info.id);
	printf("%s\n", info.first_name);
	printf("%s\n", info.last_name);

	for (int i = 0; i < info.num_courses; i++) {
		printf("%s %d\n", info.c_info[i].name, info.c_info[i].id);
	}

	printf("\n");
}

/*
 * Description:	Write student info to file
 * Parameters:	Pointer to head of LList
 * Returns:	void
**/
void save(StudentInfo *head) {
	FILE *fp = fopen("studentList.txt", "w");

	for (StudentInfo *s = head; s->next != NULL; s = s->next) {
		fprintf(fp, "%s\n", s->id);
		fprintf(fp, "%s\n", s->first_name);
		fprintf(fp, "%s\n", s->last_name);
		fprintf(fp, "%d\n", s->num_courses);

		for (int i = 0; i < s->num_courses; i++) {
			fprintf(fp, "%s %d\n", s->c_info[i].name, s->c_info[i].id);
		}
	}
	fprintf(fp, "%s", "***");

	fclose(fp);
}
/*
 * Description:	Load info from a file
 * Parameters:	Pointer to head of LList
 * Returns:	void
**/
void load(StudentInfo *head) {
	char buff[255];
	FILE *fp = fopen("studentList.txt", "r");

	StudentInfo tmp;
	int counter = 0;

	while (fscanf(fp, "%s", buff) != EOF) {
		printf("%s\n", buff);
		if (strcmp(buff, "***") == 0) {
			break;
		}
		else if (counter == 0) {
			strcpy(tmp.id, buff);
		}
		else if (counter == 1) {
			strcpy(tmp.first_name, buff);
		}
		else if (counter == 2) {
			strcpy(tmp.last_name, buff);
		}
		else if (counter == 3) {
			tmp.num_courses = atoi(buff);
			for (int i = 0; i < tmp.num_courses; i++) {
				CourseInfo n_info;
				fscanf(fp, "%s %d", n_info.name, &(n_info.id));

				tmp.c_info[i] = n_info;
			}
		}

		counter++;

		if (counter > 3) {
			counter = 0;
			printf("11 ");
			addStudentInfo(head, &tmp);
			printf("12 ");
		}
	}
}