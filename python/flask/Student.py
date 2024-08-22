
sammy = Student(firstname='Sammy',
                lastname='Shark',
                email='sammyshark@example.com',
                age=20,
                bio='Marine biology student')

carl = Student(firstname='Carl',
                lastname='White',
                email='carlwhite@example.com',
                age=22,
                bio='Marine geology student')

db.session.add(sammy)
db.session.add(carl)
db.session.commit()



# open a interactive flask shell via terminal in this working directory
# run <flask shell> command to open the interactive flask shell
# copy those stuffs above and paste them into the shell like this

# >>> sammy = Student(firstname='Sammy',
# ...                 lastname='Shark',
# ...                 email='sammyshark@example.com',
# ...                 age=20,
# ...                 bio='Marine biology student')
# >>> 
# >>> carl = Student(firstname='Carl',
# ...                 lastname='White',
# ...                 email='carlwhite@example.com',
# ...                 age=22,
# ...                 bio='Marine geology student')
# >>> 
# >>> db.session.add(ssammy)
# >>> db.session.add(carl)
# >>> db.session.commit()
# >>> 

# run these code and we've added new two student into the flask.db using Object relational mapping
# eliminate the original sql command for CRUD task.

#@
# we interact with flask.db via flask shell 

# >>> Student.query.all()
# [<Student Sammy>, <Student Carl>]
# >>> 

# >>> Student.query.filter_by(firstname='Sammy').all()
# [<Student Sammy>]
# >>> 

# >>> Student.query.filter_by(firstname='Sammy').first()
# <Student Sammy>
# >>> 

# >>> Student.query.filter_by(id=2).first()
# <Student Carl>
# >>> 

# using query.get(primary_key)
# >>> Student.query.get(2)
# <Student Carl>
# >>> 




